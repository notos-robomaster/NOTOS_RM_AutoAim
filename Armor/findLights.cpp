#include "Armor.h"

/**
 * @brief delete the reflection of the ground light
 * @param lights
 */
void eraseErrorRepeatLight(vector<LightBar> &lights);

/**
* @brief find all the possible lights of armor
*/
void ArmorDetector::findLights()
{
    vector<vector<Point>> lightContours;
    Mat contourImg;
    srcImg_binary.copyTo(contourImg);
    findContours(contourImg, lightContours, 0, 2);  // CV_RETR_EXTERNAL = 0, CV_CHAIN_APPROX_SIMPLE = 2   most time-consuming
    RotatedRect lightRect;
    LightBar light;
    for (const auto &lightContour: lightContours)
    {
        if (lightContour.size() < 6) continue;
        if (contourArea(lightContour) < armorParam.min_area) continue;

        lightRect = fitEllipse(lightContour);
        light = LightBar(lightRect);

        if (abs(light.angle) > armorParam.max_angle) continue;

        eraseErrorRepeatLight(lights);

        lights.emplace_back(light);
    }
    if (lights.size() < 2)
    {
        state = LIGHTS_NOT_FOUND;
        return;
    }

    // sort the lightBars from left to right
    sort(lights.begin(), lights.end(), [](LightBar &a1, LightBar &a2)
    {
        return a1.center.x < a2.center.x;
    });
    state = LIGHTS_FOUND;
    return;
}

void eraseErrorRepeatLight(vector<LightBar> &lights)
{
    int length = lights.size();
    vector<LightBar>::iterator it = lights.begin();
    for (size_t i = 1; i < length; i++)
        for (size_t j = i + 2; j < length; j+=2)
            if (abs(lights[i].center.x - lights[j].center.x) < 100)
                if(abs(lights[i].center.y - lights[j].center.y) < 450)
                    lights[i].center.y > lights[j].center.y ?
                    it = lights.erase(it + i) : it = lights.erase(it + j);
}
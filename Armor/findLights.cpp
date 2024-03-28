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

#ifdef REFLECTION_LIGHT
        eraseErrorRepeatLight(lights);
#endif // REFLECTION_LIGHT

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
    if (lights.size() > 4)
    {
        int sum_y = 0;
        for (const auto &light : lights)
        {
            sum_y += light.center.y;
        }
        int mean = sum_y / lights.size();

        int variance = 0;
        for (const auto &light : lights)
        {
            int deviation = light.center.y - mean;
            variance += deviation * deviation;
        }
        variance /= lights.size();

        if (variance > armorParam.max_light_y_variance)
        {
            auto it = lights.begin();
            while (it != lights.end())
            {
                if (it->center.y > mean)
                {
                    it = lights.erase(it);
                } else
                {
                    ++it;
                }
            }
        }
    }
    else
    {
        return;
    }
}
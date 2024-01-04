#include "Armor.h"

ArmorParam armorParam = ArmorParam();

ArmorDetector::ArmorDetector()
{
    state = LIGHTS_NOT_FOUND;
}

ArmorDetector::~ArmorDetector() {}

void ArmorDetector::resetDetector()
{
    state = LIGHTS_NOT_FOUND;
    lights.clear();
    armors.clear();
}

void ArmorDetector::setEnemyColor(Color enemyColor)
{
    this->enemyColor = enemyColor;
}

void ArmorDetector::setTargetNum(const int &targetNum)
{
    this->targetNum = targetNum;
}

void ArmorDetector::setImg(Mat &src)
{
    src.copyTo(srcImg);
    classifier.loadImg(srcImg);
    srcImg_binary = Mat::zeros(srcImg.size(), CV_8UC1);

    uchar *pdata = (uchar *) srcImg.data;
    uchar *qdata = (uchar *) srcImg_binary.data;
    int srcData = srcImg.rows * srcImg.cols;
    if (enemyColor == RED)
    {
        for (int i = 0; i < srcData; i++)
        {
            if (*(pdata + 2) - *pdata > armorParam.color_threshold)
                *qdata = 255;
            pdata += 3;
            qdata++;
        }
    }
    else if (enemyColor == BLUE)
    {
        for (int i = 0; i < srcData; i++)
        {
            if (*pdata - *(pdata + 2) > armorParam.color_threshold)
                *qdata = 255;
            pdata += 3;
            qdata++;
        }
    }

    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    dilate(srcImg_binary, srcImg_binary, kernel);
}

void ArmorDetector::loadSVM(const char *model_path, Size armorImgSize)
{
    classifier.loadSvmModel(model_path, armorImgSize);
}

void ArmorDetector::run(Mat &src)
{
    this->setImg(src);
    resetDetector();
    findLights();

    if (state == LIGHTS_FOUND)
    {
        matchArmors();

        if (state == ARMOR_FOUND)
        {
            setTargetArmor();
        }
    }
}

void ArmorDetector::getTargetInfo(vector<Point2f> &armorVertices, Point2f &centerPoint, ArmorType &type)
{
    armorVertices.clear();
    armorVertices = targetArmor.armorVertices;
    centerPoint = targetArmor.center;
    type = targetArmor.type;
}

bool ArmorDetector::isFoundArmor()
{
    if (state == ARMOR_FOUND)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


////////////////////////////// functions for debugging //////////////////////////////

void showLights(Mat &image, const vector<LightBar> &lights)
{
    Mat lightDisplay;
    image.copyTo(lightDisplay);
    if (!lights.empty())
    {
        putText(lightDisplay, "LIGHTS FOUND!", Point(20, 40),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255), 1, 8, false);
        for (auto light: lights)
        {
            Point2f lightVertices[4];
            light.lightRect.points(lightVertices);
            for (size_t i = 0; i < 4; i++)
            {
                line(lightDisplay, lightVertices[i], lightVertices[(i + 1) % 4], Scalar(255, 0, 255), 1, 8, 0);
            }
//            circle(lightDisplay, light.center, 1, Scalar(0, 255, 0), 2, 8, 0);
            putText(lightDisplay, to_string(int(light.center.x)), light.center,
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0), 1, 8, false);
            putText(lightDisplay, to_string(int(light.center.y)), light.center + Point2f(0, 15),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0), 1, 8, false);
        }
    }
    else
    {
        putText(lightDisplay, "LIGHTS NOT FOUND!", Point(20, 40),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1, 8, false);
    }
    imshow("Lights Monitor", lightDisplay);
}

void showArmors(Mat &image, const vector<ArmorBox> &armors, const ArmorBox &targetArmor)
{
    Mat armorDisplay;
    image.copyTo(armorDisplay);
    if (!armors.empty())
    {
        putText(armorDisplay, "ARMOR FOUND!", Point(20, 40),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 0), 1, 8, false);
        for (auto armor : armors)
        {
            circle(armorDisplay, armor.center, 2, Scalar(0, 255, 0), 2);
            for (size_t i = 0; i < 4; i++)
            {
                line(armorDisplay, armor.armorVertices[i], armor.armorVertices[(i + 1) % 4],
                     Scalar(255, 255, 0), 1, 8, 0);
            }
            putText(armorDisplay, "Armor Number: " + to_string(int(armor.armorNum)), armor.center,
                    FONT_HERSHEY_PLAIN, 1, Scalar(255, 255, 255), 1, 8, false);
            putText(armorDisplay, to_string(int(armor.center.x)), armor.center + Point2f(5, 15),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0), 1, 8, false);
            putText(armorDisplay, to_string(int(armor.center.y)), armor.center + Point2f(5, 30),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0), 1, 8, false);
            putText(armorDisplay, "Angle difference: " + to_string(float(armor.getAngleDiff())), armor.center + Point2f(10, 45),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 97, 255), 1, 8, false);
            putText(armorDisplay, "Deviation Angle: " + to_string(float(armor.getDeviationAngle())), armor.center + Point2f(10, 60),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 97, 255), 1, 8, false);
            putText(armorDisplay, "X Dislocation Ration: " + to_string(float(armor.getDislocationX())), armor.center + Point2f(10, 75),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 97, 255), 1, 8, false);
            putText(armorDisplay, "Y Dislocation Ration: " + to_string(float(armor.getDislocationY())), armor.center + Point2f(10, 90),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 97, 255), 1, 8, false);
            putText(armorDisplay, "Length Ration: " + to_string(float(armor.getLengthRation())), armor.center + Point2f(10, 105),
                    FONT_HERSHEY_PLAIN, 1, Scalar(0, 97, 255), 1, 8, false);
        }
        for (size_t i = 0; i < 4; i++)
        {
            line(armorDisplay, targetArmor.armorVertices[i], targetArmor.armorVertices[(i + 1) % 4],
                 Scalar(255, 255, 255), 1, 8, 0);
        }
    }
    else
    {
        putText(armorDisplay, "ARMOR NOT FOUND!", Point(20, 40),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 255), 1, 8, false);
    }
    imshow("Armor Monitor", armorDisplay);
}

void textLights(vector<LightBar> &lights)
{
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------LIGHTS------------\n");
    if (lights.empty())
    {
        fmt::print(fmt::fg(fmt::color::red), "LIGHTS NOT FOUND\n");
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::yellow), "LIGHTS FOUND\n");
        for (size_t i = 0; i < lights.size(); i++)
        {
            fmt::print(fmt::fg(fmt::color::green), "Light Center: {} {}\n",
                       to_string(int(lights[i].center.x)), to_string(int(lights[i].center.y)));
        }
        fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    }
}

void textArmors(vector<ArmorBox> &armors)
{
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------ARMORS------------\n");
    if (armors.empty())
    {
        fmt::print(fmt::fg(fmt::color::purple), "ARMORS NOT FOUND\n");
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::cyan), "ARMORS FOUND\n");
        for (size_t i = 0; i < armors.size(); i++)
        {
            if (armors[i].type == SMALL_ARMOR)
                fmt::print(fmt::fg(fmt::color::cyan), "Armor Type: SMALL ARMOR\n");
            else if (armors[i].type == BIG_ARMOR)
                fmt::print(fmt::fg(fmt::color::cyan), "Armor Type: BIG ARMOR\n");
            fmt::print(fmt::fg(fmt::color::white), "Armor Number: {}\n", armors[i].armorNum);
            fmt::print(fmt::fg(fmt::color::green), "Armor Center: {} {}\n",
                       to_string(int(armors[i].center.x)), to_string(int(armors[i].center.y)));
            fmt::print(fmt::fg(fmt::color::orange), "Angle difference: {}\n", armors[i].getAngleDiff());
            fmt::print(fmt::fg(fmt::color::orange), "Deviation Angle: {}\n", armors[i].getDeviationAngle());
            fmt::print(fmt::fg(fmt::color::orange), "X Dislocation Ration: {}\n", armors[i].getDislocationX());
            fmt::print(fmt::fg(fmt::color::orange), "Y Dislocation Ration: {}\n", armors[i].getDislocationY());
            fmt::print(fmt::fg(fmt::color::orange), "Length Ration: {}\n", armors[i].getLengthRation());
        }
        fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    }
}

void textScores(vector<ArmorBox> &armors, ArmorBox &lastArmor)
{
    if (!armors.empty())
    {
        fmt::print(fmt::fg(fmt::color::gray), "\n-----------SCORES------------\n");
        for (size_t i = 0; i < armors.size(); i++)
        {
            float score = 0;
            fmt::print(fmt::fg(fmt::color::green), "Armor Center: {} {}\n",
                       to_string(int(armors[i].center.x)), to_string(int(armors[i].center.y)));
            fmt::print(fmt::fg(fmt::color::green), "Area: {}\n", armors[i].armorRect.area());
            score += armors[i].armorRect.area();

            if (lastArmor.armorNum != 0)
            {
                float a_distance = getPointsDistance(armors[i].center, lastArmor.center);
                fmt::print(fmt::fg(fmt::color::green), "Points Distance: {}\n", a_distance);
                score -= a_distance * 2;
                fmt::print(fmt::fg(fmt::color::red), "Score: {}\n", score);
            }
        }
        fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    }
}

void ArmorDetector::showDebugInfo()
{
#ifdef DETECT_DEBUG_MOOD
#ifdef SHOW_SRCIMG
    imshow("srcImg", srcImg);
#endif  // SHOW_SRCIMG
#ifdef SHOW_SRCBINARY
    imshow("srcImg_Binary", srcImg_binary);
#endif  // SHOW_SRCBINARY
#ifdef SHOW_LIGHTS
    showLights(srcImg, lights);
#endif  // SHOW_LIGHTS
#ifdef SHOW_ARMORS
    showArmors(srcImg, armors, targetArmor);
#endif  // SHOW_ARMORS
#ifdef TEXT_LIGHTS
    textLights(lights);
#endif  // TEXT_LIGHTS
#ifdef TEXT_ARMORS
    textArmors(armors);
#endif  // TEXT_ARMORS
#ifdef TEXT_SCORES
    textScores(armors, lastArmor);
#endif  // TEXT_SCORES
#endif // DETECT_DEBUG_MOOD
}
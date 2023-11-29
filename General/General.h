#ifndef GENERAL_H
#define GENERAL_H

#include <opencv2/opencv.hpp>
#include <iostream>
//#include <math.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include "../Debug.h"

using namespace cv;
using namespace std;
using namespace ml;

// extern variables
extern cv::Mat src;

/**
 * @brief image init
 */
void imageInit();

/**
 * @brief image updating
 */
void imageUpdating();

/**
 * @brief fps init
 */
void fpsInit();

/**
 * @brief fps updating
 */
void fpsUpdating();

/**
 * @brief autoaim run
 */
void autoaimRun();

enum ArmorType
{
    SMALL_ARMOR = 0,
    BIG_ARMOR = 1
};

/**
 * @brief colors in order
 */
enum Color
{
    BLUE = 0,
    GREEN = 1,
    RED = 2
};

/**
 * @brief get the distance between two points
 * @param a
 * @param b
 * @return two points distance
 */
float getPointsDistance(const Point2f &a, const Point2f &b);

#endif //GENERAL_H

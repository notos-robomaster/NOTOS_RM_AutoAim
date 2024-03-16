#ifndef KALMAN_H
#define KALMAN_H

#include <opencv2/opencv.hpp>
#include "../Debug.h"

using namespace cv;

class Kalman
{
public:
    Kalman();

    /**
     * @brief run prediction kalman
     * @param point
     * @return predicted point
     */
    Point2f predictRun(Point2f &point);

    /**
     * @brief show prediction image
     * @param image
     * @param statePt
     * @param predictPt
     */
    void showPredict(Mat &image, Point &statePt, Point &predictPt);

    /**
     * @brief show all predict debug info
     * @param image
     */
    void showDebugInfo(Mat &image);

private:
    const int stateNum = 4;
    const int measureNum = 2;

    KalmanFilter KF;
    Mat state;
    Mat processNoise;
    Mat measurement;
    Mat control;

    Point statePt;  // former point
    Point predictPt;    // predict point
};

#endif  // KALMAN_H
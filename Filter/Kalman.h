#ifndef KALMAN_H
#define KALMAN_H

#include <opencv2/opencv.hpp>
#include "../Debug.h"

using namespace cv;

class Kalman
{
public:
    Kalman();

    // run prediction kalman
    Point2f predictRun(Point2f &point);

    // show prediction image
    void showPredict(Mat &image, Point &statePt, Point &predictPt);

    // show all predict debug info
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
#ifndef KALMAN_H
#define KALMAN_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Kalman
{
public:
    Kalman();

    void predictRun(Point2f &point);

    void showPredict(Mat &image, Point &statePt, Point &predictPt);

    void showDebugInfo(Mat &image);

private:
    const int stateNum = 4;
    const int measureNum = 2;

    KalmanFilter KF;
    Mat state;
    Mat processNoise;
    Mat measurement;

    Point statePt;
    Point predictPt;
};

#endif  // KALMAN_H
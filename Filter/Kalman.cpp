#include "Kalman.h"

Kalman::Kalman()
{
    KF = KalmanFilter(stateNum, measureNum, 0);
    state = Mat(stateNum, 1, CV_32FC1);
    processNoise = Mat(stateNum, 1, CV_32F);
    measurement = Mat::zeros(measureNum, 1, CV_32F);

    randn(state, Scalar::all(0), Scalar::all(0.1));
    KF.transitionMatrix = (Mat_<float>(4, 4) <<
            1, 0, 1, 0,
            0, 1, 0, 1,
            0, 0, 1, 0,
            0, 0, 0, 1);
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, Scalar::all(1e-5));
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
    setIdentity(KF.errorCovPost, Scalar::all(1));

    randn(KF.statePost, Scalar::all(0), Scalar::all(0.1));
}

void Kalman::predictRun(Point2f &point)
{
    for (;;)
    {
        statePt = Point((int) KF.statePost.at<float>(0), (int) KF.statePost.at<float>(1));
        Mat prediction = KF.predict();
        predictPt = Point((int) prediction.at<float>(0), (int) prediction.at<float>(1));

        measurement.at<float>(0) = (float) point.x;
        measurement.at<float>(1) = (float) point.y;

        KF.correct(measurement);
    }
}

void showPredict(Mat &image, Point &statePt, Point &predictPt)
{
    Mat predictDisplay;
    image.copyTo(predictDisplay);
    circle(predictDisplay, statePt, 5, CV_RGB(255,0,0),1);
    circle(predictDisplay, predictPt, 5, Scalar(255, 0, 0), 1);

    imshow("Lights Monitor", predictDisplay);
}

void Kalman::showDebugInfo(Mat &image)
{
    showPredict(image, statePt, predictPt);
}
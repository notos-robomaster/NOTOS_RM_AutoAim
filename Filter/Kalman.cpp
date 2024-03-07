#include "Kalman.h"

Kalman::Kalman()
{
    KF = KalmanFilter(stateNum, measureNum, 0);
    state = Mat(stateNum, 1, CV_32FC1);
    processNoise = Mat(stateNum, 1, CV_32F);
    measurement = Mat::zeros(measureNum, 1, CV_32F);

    randn(state, Scalar::all(0), Scalar::all(0.1));

    //!< state transition matrix (A)
    KF.transitionMatrix = (Mat_<float>(4, 4) <<
            1, 0, 1, 0,
            0, 1, 0, 1,
            0, 0, 1, 0,
            0, 0, 0, 1);

    //!< measurement matrix (H)
    setIdentity(KF.measurementMatrix);

    //!< process noise covariance matrix (Q)
    KF.processNoiseCov *= 1;
    setIdentity(KF.processNoiseCov, Scalar::all(1e-5));

    //!< measurement noise covariance matrix (R)
    KF.measurementNoiseCov *= 1;
    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));

    //!< posteriori error estimate covariance matrix (P(k)): P(k)=(I-K(k)*H)*P'(k)
    KF.errorCovPost *= 1;
    setIdentity(KF.errorCovPost, Scalar::all(1));

    //!< Kalman gain matrix (K(k)): K(k)=P'(k)*Ht*inv(H*P'(k)*Ht+R)
    Mat control = -KF.gain * (measurement - KF.measurementMatrix * KF.statePost);

    // !< corrected state (x(k)): x(k)=x'(k)+K(k)*(z(k)-H*x'(k))
    randn(KF.statePost, Scalar::all(0), Scalar::all(0.1));
}

Point2f Kalman::predictRun(Point2f &point)
{
    statePt = Point((int) KF.statePost.at<float>(0), (int) KF.statePost.at<float>(1));
    Mat prediction = KF.predict();
    predictPt = Point((int) prediction.at<float>(0), (int) prediction.at<float>(1));

    measurement.at<float>(0) = (float) point.x;
    measurement.at<float>(1) = (float) point.y;

    KF.correct(measurement);

    return predictPt;
}

void Kalman::showPredict(Mat &image, Point &statePt, Point &predictPt)
{
    Mat predictDisplay;
    image.copyTo(predictDisplay);
    circle(predictDisplay, statePt, 5, Scalar(0,0,255), 2);
    circle(predictDisplay, predictPt, 5, Scalar(255, 255, 0), 2);

    imshow("Predict Monitor", predictDisplay);
}

void Kalman::showDebugInfo(Mat &image)
{
#ifdef PREDICT_DEBUG_MOOD
#ifdef SHOW_PREDICT
    showPredict(image, statePt, predictPt);
#endif  // SHOW_PREDICT
#endif  // PREDICT_DEBUG_MOOD
}
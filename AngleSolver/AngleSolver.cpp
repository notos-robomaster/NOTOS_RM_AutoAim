#include "AngleSolver.h"

AngleSolver::AngleSolver()
{}

AngleSolver::~AngleSolver()
{}

void AngleSolver::setCameraParam(const cv::Mat &camera_matrix, const cv::Mat &distortion_coeff)
{
    camera_matrix.copyTo(CAMERA_MATRIX);
    distortion_coeff.copyTo(DISTORTION_COEFF);
}

int AngleSolver::setCameraParam(const char *filePath, int camId)    // todo camId to debug
{
    FileStorage fsRead;
    fsRead.open(filePath, FileStorage::READ);
    if (!fsRead.isOpened())
    {
        cerr << "Failed to open xml for reading" << endl;
        return -1;
    }

    fsRead["X_DISTANCE_BETWEEN_GUN_AND_CAM"] >> GUN_CAM_DISTANCE_X;
    fsRead["Y_DISTANCE_BETWEEN_GUN_AND_CAM"] >> GUN_CAM_DISTANCE_Y;

    Mat camera_matrix;
    Mat distortion_coeff;
    switch (camId)
    {
        case 1:
            fsRead["CAMERA_MATRIX_1"] >> camera_matrix;
            fsRead["DISTORTION_COEFF_1"] >> distortion_coeff;
            break;
        case 2:
            fsRead["CAMERA_MATRIX_2"] >> camera_matrix;
            fsRead["DISTORTION_COEFF_2"] >> distortion_coeff;
            break;
        case 3:
            fsRead["CAMERA_MATRIX_3"] >> camera_matrix;
            fsRead["DISTORTION_COEFF_3"] >> distortion_coeff;
            break;
        default:
            cerr << "wrong CamId given!" << endl;
            break;
    }
    setCameraParam(camera_matrix, distortion_coeff);
    fsRead.release();
    return 0;
}

void AngleSolver::setArmorSize(ArmorType type, double width, double height)
{
    double half_x = width / 2.0;
    double half_y = height / 2.0;
    switch (type)
    {
        case SMALL_ARMOR:
            SMALL_ARMOR_POINTS_3D.push_back(Point3f(-half_x, half_y, 0));
            SMALL_ARMOR_POINTS_3D.push_back(Point3f(half_x, half_y, 0));
            SMALL_ARMOR_POINTS_3D.push_back(Point3f(half_x, -half_y, 0));
            SMALL_ARMOR_POINTS_3D.push_back(Point3f(-half_x, -half_y, 0));
            break;
        case BIG_ARMOR:
            BIG_ARMOR_POINTS_3D.push_back(Point3f(half_x, -half_y, 0));
            BIG_ARMOR_POINTS_3D.push_back(Point3f(half_x, half_y, 0));
            BIG_ARMOR_POINTS_3D.push_back(Point3f(-half_x, half_y, 0));
            BIG_ARMOR_POINTS_3D.push_back(Point3f(-half_x, -half_y, 0));
            break;
        default:
            break;
    }
}

void AngleSolver::setBulletSpeed(int bulletSpeed)   // todo customize the bullet speed
{
    BULLET_SPEED = bulletSpeed;
}

void AngleSolver::setTarget(vector<cv::Point2f> contourPoints, cv::Point2f centerPoint, ArmorType type)
{
    targetContour = contourPoints;
    targetCenter = centerPoint;
    targetType = type;
}

void AngleSolver::solveAngles()
{
    Mat _rvec;
    switch (targetType)
    {
        case SMALL_ARMOR:
            solvePnP(SMALL_ARMOR_POINTS_3D, targetContour, CAMERA_MATRIX, DISTORTION_COEFF,
                     _rvec, tVec, false, SOLVEPNP_ITERATIVE);
            break;
        case BIG_ARMOR:
            solvePnP(BIG_ARMOR_POINTS_3D, targetContour, CAMERA_MATRIX, DISTORTION_COEFF,
                     _rvec, tVec, false, SOLVEPNP_ITERATIVE);
            break;
        default:
            break;
    }

//    GUN_CAM_DISTANCE_X = -125;
//    GUN_CAM_DISTANCE_Y = -50;
    GUN_CAM_DISTANCE_X = 0;
    GUN_CAM_DISTANCE_Y = 0;
    tVec.at<double>(0, 0) -= GUN_CAM_DISTANCE_X;
    tVec.at<double>(1, 0) -= GUN_CAM_DISTANCE_Y;
    distance = norm(tVec);

    if (distance > 5000)
    {
        PinHole_solver();
    }
    else
    {
        P4P_solver();
    }
}

void AngleSolver::P4P_solver()
{
    double x_pos = tVec.at<double>(0, 0);
    double y_pos = tVec.at<double>(1, 0);
    double z_pos = tVec.at<double>(2, 0);
    double tan_pitch = y_pos / sqrt(x_pos * x_pos + z_pos * z_pos);
    double tan_yaw = x_pos / z_pos;
    x_pitch = -atan(tan_pitch) * 180 / CV_PI;
    y_yaw = atan(tan_yaw) * 180 / CV_PI;
}

void AngleSolver::PinHole_solver()
{
    double fx = CAMERA_MATRIX.at<double>(0, 0);
    double fy = CAMERA_MATRIX.at<double>(1, 1);
    double cx = CAMERA_MATRIX.at<double>(0, 2);
    double cy = CAMERA_MATRIX.at<double>(1, 2);
    Point2f pnt;
    vector<cv::Point2f> in;
    vector<cv::Point2f> out;
    in.push_back(targetCenter);

    undistortPoints(in, out, CAMERA_MATRIX, DISTORTION_COEFF, noArray(), CAMERA_MATRIX);
    pnt = out.front();

    double rxNew = (pnt.x - cx) / fx;
    double ryNew = (pnt.y - cy) / fy;

    y_yaw = atan(rxNew) * 180 / CV_PI;
    x_pitch= -atan(ryNew) * 180 / CV_PI;
}

void AngleSolver::compensateAngle()
{
    compensateOffset();
    compensateGravity();
}

void AngleSolver::compensateOffset()
{
    float camera_target_height = distance * sin(x_pitch / 180 * CV_PI);
    float gun_target_height = camera_target_height + GUN_CAM_DISTANCE_Y;
    float gun_pitch_tan = gun_target_height / (distance * cos(x_pitch / 180 * CV_PI));
    x_pitch = atan(gun_pitch_tan) * 180 / CV_PI;
}

void AngleSolver::compensateGravity()
{
    float compensateGravity_pitch_tan = tan(x_pitch / 180 * CV_PI) +
            (0.5 * 9.788 * (distance / BULLET_SPEED) * (distance / BULLET_SPEED) / cos(x_pitch / 180 * CV_PI));
    x_pitch = atan(compensateGravity_pitch_tan) * 180 / CV_PI;
}

void AngleSolver::getAngle(vector<cv::Point2f> &contourPoints, cv::Point2f centerPoint, ArmorType type,
                           double &yaw, double &pitch, double &evaluateDistance)
{
    setTarget(contourPoints, centerPoint, type);
    solveAngles();
    compensateAngle();
    yaw = y_yaw;
    pitch = x_pitch;
    evaluateDistance = distance;
}

////////////////////////////// functions for debugging //////////////////////////////

void AngleSolver::showDebugInfo()
{
#ifdef SOLVER_DEBUG_MOOD
#ifdef SHOW_ANGLE
    Mat angleImage = Mat::zeros(250, 420, CV_8UC3);
    putText(angleImage, "Yaw: " + to_string(y_yaw), Point(50, 50),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 215, 255), 1, 8, false);
    putText(angleImage, "Pitch: " + to_string(x_pitch), Point(50, 100),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 215, 255), 1, 8, false);
    putText(angleImage, "Distance: " + to_string(distance), Point(50, 150),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 215, 255), 1, 8, false);
    putText(angleImage, "X:" + to_string((int)(tVec.at<double>(0))), Point(50, 200),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 125, 255), 1, 8, false);
    putText(angleImage, "Y:" + to_string((int)(tVec.at<double>(1))), Point(158, 200),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 125, 255), 1, 8, false);
    putText(angleImage, "Z:" + to_string((int)(tVec.at<double>(2))), Point(275, 200),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 125, 255), 1, 8, false);
    imshow("AngleSolver", angleImage);
#endif // SHOW_ANGLE
#ifdef TEXT_TVEC
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------TVEC------------\n");
    fmt::print(fmt::fg(fmt::color::red), "X: {}\n", tVec.at<double>(0, 0));
    fmt::print(fmt::fg(fmt::color::red), "Y: {}\n", tVec.at<double>(1, 0));
    fmt::print(fmt::fg(fmt::color::red), "Z: {}\n", tVec.at<double>(2, 0));
    fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
#endif // TEXT_TVEC
    float yaw_temp = y_yaw, pitch_temp = x_pitch;
#ifdef TEXT_P4P
    P4P_solver();
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------P4PSOLVER------------\n");
    fmt::print(fmt::fg(fmt::color::green), "Yaw: {} Pitch: {}\n", y_yaw, x_pitch);
    fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    y_yaw = yaw_temp; x_pitch = pitch_temp;
#endif // TEXT_P4P
#ifdef TEXT_PINHOLE
    PinHole_solver();
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------PinHoleSOLVER------------\n");
    fmt::print(fmt::fg(fmt::color::green), "Yaw: {} Pitch: {}\n", y_yaw, x_pitch);
    fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    y_yaw = yaw_temp; x_pitch = pitch_temp;
#endif // TEXT_PINHOLE
#ifdef TEXT_COMPENSATION
    solveAngles();
    float raw_pitch;
    raw_pitch = x_pitch;
    compensateOffset();
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------COMPENSATION------------\n");
    fmt::print(fmt::fg(fmt::color::purple), "Gun-Camera Offset: {}\n", x_pitch - raw_pitch);
    fmt::print(fmt::fg(fmt::color::green), "Yaw: {} Pitch: {}\n", y_yaw, x_pitch);
    fmt::print(fmt::fg(fmt::color::gray), "- - - - - - - - - - - -\n");

    solveAngles();
    compensateGravity();
    fmt::print(fmt::fg(fmt::color::purple), "Gravity: {}\n", x_pitch - raw_pitch);
    fmt::print(fmt::fg(fmt::color::green), "Yaw: {} Pitch: {}\n", y_yaw, x_pitch);
    fmt::print(fmt::fg(fmt::color::gray), "- - - - - - - - - - - -\n");

    solveAngles();
    compensateAngle();
    fmt::print(fmt::fg(fmt::color::purple), "Pitch Compensation: {}\n", x_pitch - raw_pitch);
    fmt::print(fmt::fg(fmt::color::green), "Yaw: {} Pitch: {}\n", y_yaw, x_pitch);
    fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
    y_yaw = yaw_temp; x_pitch = pitch_temp;
#endif // TEXT_COMPENSATION
#ifdef TEXT_CAMERA_PARAMS
    fmt::print(fmt::fg(fmt::color::gray), "\n-----------CAMERAPARAMS------------\n");
    cout << "CAMERA MATRIX:" << endl;
    cout << CAMERA_MATRIX << endl;
    fmt::print(fmt::fg(fmt::color::gray), "- - - - - - - - - - - -\n");
    cout << "DISTORTION COEFF" << endl;
    cout << DISTORTION_COEFF << endl;
    fmt::print(fmt::fg(fmt::color::gray), "-----------------------\n");
#endif // TEXT_CAMERA_PARAMS
#endif // SOLVER_DEBUG_MOOD
}
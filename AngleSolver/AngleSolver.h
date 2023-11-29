#ifndef ANGLESOLVER_H
#define ANGLESOLVER_H

#include "../General/General.h"

using namespace cv;
using namespace std;

class AngleSolver
{
public:
    AngleSolver();
    ~AngleSolver();

    /**
     * @brief set camera params
     * @param camera_matrix
     * @param distortion_coeff
     */
    void setCameraParam(const cv::Mat &camera_matrix, const cv::Mat &distortion_coeff);

    /**
     * @brief set camera xml file
     * @param filePath
     * @param camId
     */
    int setCameraParam(const char *filePath, int camId);

    /**
     * @brief set armor size
     * @param type
     * @param width
     * @param height
     */
    void setArmorSize(ArmorType type, double width, double height);

    /**
     * @brief set bullet speed
     * @param bulletSpeed
     */
    void setBulletSpeed(int bulletSpeed);

    /**
     * @brief set target armor contour points and centerPoint
     * @param contourPoints
     * @param centerPoint
     * @param type
     */
    void setTarget(vector<Point2f> contourPoints, Point2f centerPoint, ArmorType type);

    /**
     * @brief solve the angles using P4P or PinHole
     */
    void solveAngles();

    /**
     * @brief solve the angles using P4P
     */
    void P4P_solver();

    /**
     * @brief solve the angles using PinHole
     */
    void PinHole_solver();

    /**
     * @brief compensation of pitch
     */
    void compensateAngle();

    /**
     * @brief compensation of pitch for y_offset between barrel and camera
     */
    void compensateOffset();

    /**
     * @brief compensation of pitch for gravity
     */
    void compensateGravity();

    /**
     * @brief according to the target2D point to get the yaw and pitch and distance and armor type using solvePnP
     * @param contourPoints
     * @param centerPoint
     * @param type
     * @param yaw
     * @param pitch
     * @param evaluateDistance
     */
    void getAngle(vector<Point2f> &contourPoints, Point2f centerPoint, ArmorType type, double &yaw, double &pitch, double &evaluateDistance);

    /**
     * @brief show all angle debug info
     */
    void showDebugInfo();

private:
    Mat CAMERA_MATRIX;  // intrinsic matrix fx, fy, cx, cy
    Mat DISTORTION_COEFF;   // distortion coefficients k1, k2, p1, p2

    vector<Point3f> SMALL_ARMOR_POINTS_3D;
    vector<Point3f> BIG_ARMOR_POINTS_3D;

    // speed of bullet (compensation for gravity and air fru)
    double BULLET_SPEED;

    // distance between camera and barrel in y-axis (positive when camera is under barrel) barrel_y = camera_y + barrel_camera_y
    double GUN_CAM_DISTANCE_Y;

    vector<Point2f> targetContour;
    Point2f targetCenter;
    ArmorType targetType;

    // s[R|t]=s' s->world coordinate; s'->camera coordinate
    Mat rVec;   // rot rotation between camera and target center
    Mat tVec;   // trans translation between camera and target center

    float y_yaw;
    float x_pitch;
    double distance;
};

#endif // ANGLESOLVER_H

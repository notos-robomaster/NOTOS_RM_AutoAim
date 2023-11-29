#ifndef ARMOR_H
#define ARMOR_H

#include "../General/General.h"

enum DetectorState
{
    LIGHTS_NOT_FOUND = 0,
    LIGHTS_FOUND = 1,
    ARMOR_NOT_FOUND = 2,
    ARMOR_FOUND = 3
};

/**
 * @brief params for armor-detection
 */
struct ArmorParam
{
    int color_threshold;
    int bright_threshold;

    float min_area; // light bar
    float max_angle; // light bar

    float max_angle_diff;   // max angle difference between two lights bars
    float max_lengthDiff_ratio; // max length ratio difference between two light bars
    float max_deviation_angle;  // max horizon angle of the line of centers of lights

    float max_x_diff_ratio; // max distance ratio in X direction
    float max_y_diff_ratio; // max distance ratio in Y direction

    // default values
    ArmorParam()
    {
        color_threshold = 100 - 20;
        bright_threshold = 60;

        min_area = 50;
        max_angle = 45;

        max_angle_diff = 6;
        max_lengthDiff_ratio = 0.5;
        max_deviation_angle = 50;

        max_x_diff_ratio = 4.5;
        max_y_diff_ratio = 0.5;
    }
};
extern ArmorParam armorParam;

/**
 * @brief information of lightBar besides the armor
 */
class LightBar
{
public:
    LightBar();
    LightBar(const RotatedRect &light);
    ~LightBar();

public:
    RotatedRect lightRect;
    float length;
    Point2f center;
    float angle;
};

/**
 * @brief information of Armor
 */
class ArmorBox
{
public:
    ArmorBox();
    ArmorBox(const LightBar &l_light,const LightBar &r_light);
    ~ArmorBox();

    // angle difference between two light bars
    float getAngleDiff() const;

    // horizon angle of the line of centers of lights
    float getDeviationAngle() const;

    // distance ratio between the centers of lights in X direction
    float getDislocationX() const;

    // distance ratio between the centers of lights in Y direction
    float getDislocationY() const;

    // length ratio difference between two light bars
    float getLengthRation() const;

    // judge whether this armor is suitable or not
    bool isSuitableArmor() const;

public:
    LightBar l_light, r_light;
    int l_index, r_index;
    int armorNum;
    vector<Point2f> armorVertices;
    ArmorType type;
    Point2f center;
    Rect armorRect;
    float armorAngle;
    Mat armorImg;
};

class ArmorNumClassifier
{
public:
    ArmorNumClassifier();
    ~ArmorNumClassifier();

    /**
     * @brief load the SVM model used to recognize armorNum
     * @param model_path
     * @param armorImgSize
     */
    void loadSvmModel(const char *model_path, Size armorImgSize = Size(40, 40));

    /**
     * @brief load the current roiImage from ArmorDetector
     * @param srcImg
     */
    void loadImg(Mat &srcImg);

    /**
     * @brief use warpPerspective to get armorImg
     * @param armor
     */
    void getArmorImg(ArmorBox &armor);

    /**
     * @brief use SVM to recognize the number of each Armor
     * @param armor
     */
    void setArmorNum(ArmorBox &armor);

private:
    Ptr<SVM> svm;
    Mat p;  // matrix for SVM
    Size armorImgSize;

    Mat warpPerspective_src;
    Mat warpPerspective_dst;
    Mat warpPerspective_mat;
    Point2f srcPoints[4];
    Point2f dstPoints[4];
};

/**
 * @brief Detector function to detect lights from srcImg, match light to armors,
 *         select target and recognize armorNumber
 */
class ArmorDetector
{
public:
    ArmorDetector();
    ~ArmorDetector();

    /**
     * @brief load svm model for detect number
     * @param model_path
     * @param armorImgSize
     */
    void loadSVM(const char *model_path, Size armorImgSize = Size(40, 40));

    /**
     * @brief reset the ArmorDetector
     */
     void resetDetector();

     /**
      * @brief set enemyColor
      * @param enemyColor
      */
      void setEnemyColor(Color enemyColor);

      /**
       * @brief set target armor number
       * @param targetNum
       */
      void setTargetNum(const int &targetNum);

      /**
       * @brief load source image and set roi if roiMode is open and found target in last frame
       * @param src
       */
      void setImg(Mat &src);

    /**
     * @brief find all the possible lights of armor
     */
    void findLights();

    /**
     * @brief match lights into armors
     */
    void matchArmors();

    /**
     * @brief choice the most suitable target armor
     */
    void setTargetArmor();

    /**
     * @brief an integrative function to run the Detector
     * @param src
     */
    void run(Mat &src);

    /**
     * @brief get targetArmor information
     * @param armorVertices
     * @param centerPoint
     * @param type
     */
    void getTargetInfo(vector<Point2f> &armorVertices, Point2f &centerPoint, ArmorType &type);

    /**
     * @brief armor detection status
     * @return whether find armor
     */
    bool isFoundArmor();

    /**
     * @brief show all detect debug info
     */
    void showDebugInfo();

private:
    Mat srcImg;
    Mat srcImg_binary;
    Color enemyColor;
    int targetNum;
    vector<LightBar> lights;
    vector<ArmorBox> armors;
    ArmorBox targetArmor;
    ArmorBox lastArmor;
    ArmorNumClassifier classifier;
    DetectorState state;
};

#endif //ARMOR_H

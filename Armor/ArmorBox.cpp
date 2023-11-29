#include "Armor.h"

const Point2f crossPoint(const Point2f &bl, const Point2f &tl, const Point2f &tr, const Point2f &br);
void setArmorVertices(const LightBar &l_light, const LightBar &r_light, ArmorBox &armor);

ArmorBox::ArmorBox()
{
    l_index = -1;
    r_index = -1;
    l_light = LightBar();
    r_light = LightBar();
    armorNum = 0;
    armorVertices.resize(4);
    type = SMALL_ARMOR;
    center = Point2f();
    armorRect = Rect();
    armorImg = Mat();
}

ArmorBox::~ArmorBox()
{}

ArmorBox::ArmorBox(const LightBar &l_light, const LightBar &r_light)
{
    this->l_light = l_light;
    this->r_light = r_light;

    armorNum = 0;
    armorAngle = (l_light.angle + r_light.angle) / 2;

    armorVertices.resize(4);
    setArmorVertices(l_light, r_light, *this);

    center = crossPoint(armorVertices[0], armorVertices[1], armorVertices[2], armorVertices[3]);

    armorRect = boundingRect(armorVertices);

    if (this->getDislocationX() > 2.5)
        type = BIG_ARMOR;
}

float ArmorBox::getAngleDiff() const
{
    float angle_diff = abs(l_light.angle - r_light.angle);
    return angle_diff;
}

float ArmorBox::getDeviationAngle() const
{
    float delta_x = r_light.center.x - l_light.center.x;
    float delta_y = r_light.center.y - l_light.center.y;
    float deviationAngle = abs(atan(delta_y / delta_x)) * 180 / CV_PI;  // tanθ=Δy/Δx  todo: atan2(delta_y, delta_x)
    return deviationAngle;
}

float ArmorBox::getDislocationX() const
{
    float meanLen = (l_light.length + r_light.length) / 2;
    float xDiff = abs(l_light.center.x - r_light.center.x);
    float xDiff_ratio = xDiff / meanLen;
    return xDiff_ratio;
}

float ArmorBox::getDislocationY() const
{
    float meanLen = (l_light.length + r_light.length) / 2;
    float yDiff = abs(l_light.center.y - r_light.center.y);
    float yDiff_ratio = yDiff / meanLen;
    return yDiff_ratio;
}

float ArmorBox::getLengthRation() const
{
    float length_diff = abs(l_light.length - r_light.length);
    float lengthDiffRation = length_diff / MAX(l_light.length, r_light.length);
    return lengthDiffRation;
}

bool ArmorBox::isSuitableArmor() const
{
    return
        this->getAngleDiff()      < armorParam.max_angle_diff      &&
        this->getDeviationAngle() < armorParam.max_deviation_angle &&
        this->getDislocationX()   < armorParam.max_x_diff_ratio    &&
        this->getDislocationY()   < armorParam.max_y_diff_ratio    &&
        this->getLengthRation()   < armorParam.max_lengthDiff_ratio;
}

/**
 * @brief calculate the cross point of cross equation
 * @param bl
 * @param tl
 * @param tr
 * @param br
 * @return cross point
 */
const Point2f crossPoint(const Point2f &bl, const Point2f &tl, const Point2f &tr, const Point2f &br)
{
    float a1 = tr.y - bl.y;
    float b1 = tr.x - bl.x;
    float c1 = bl.x*tr.y - tr.x*bl.y;

    float a2 = br.y - tl.y;
    float b2 = br.x - tl.x;
    float c2 = tl.x*br.y - br.x*tl.y;

    float d = a1 * b2 - a2 * b1;

    if (d == 0.0)
    {
        return Point2f(FLT_MAX, FLT_MAX);
    }
    else
    {
        return cv::Point2f((b2*c1 - b1*c2) / d, (c1*a2 - c2*a1) / d);
    }
}

/**
 * @brief using the 4points of lightBar to construct the armorVertices
 * @param l_light
 * @param r_light
 * @param armor
 */
void setArmorVertices(const LightBar &l_light, const LightBar &r_light, ArmorBox &armor)
{
    cv::Size exLSize(int(l_light.lightRect.size.width), int(l_light.lightRect.size.height * 2));    // todo float
    cv::Size exRSize(int(r_light.lightRect.size.width), int(r_light.lightRect.size.height * 2));
    cv::RotatedRect exLLight(l_light.center, exLSize, armor.armorAngle);
    cv::RotatedRect exRLight(r_light.center, exRSize, armor.armorAngle);

    cv::Point2f pts_l[4];
    exLLight.points(pts_l);
    cv::Point2f upper_l = pts_l[2];
    cv::Point2f lower_l = pts_l[3];

    cv::Point2f pts_r[4];
    exRLight.points(pts_r);
    cv::Point2f upper_r = pts_r[1];
    cv::Point2f lower_r = pts_r[0];

    armor.armorVertices[0] = upper_l;
    armor.armorVertices[1] = upper_r;
    armor.armorVertices[2] = lower_r;
    armor.armorVertices[3] = lower_l;
}
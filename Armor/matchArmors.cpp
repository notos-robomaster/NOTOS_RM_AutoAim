#include "Armor.h"

void eraseErrorRepeatArmor(vector<ArmorBox> &armors);
bool armorCompare(const ArmorBox &a_armor, const ArmorBox &b_armor, const ArmorBox &lastArmor, const int &targetNum);

void ArmorDetector::matchArmors()
{
    for (int i = 0; i < lights.size() - 1; i++) // todo time complexity problem
    {
        for (int j = i + 1; j < lights.size(); j++)
        {
            ArmorBox armor = ArmorBox(lights[i], lights[j]);
            if (armor.isSuitableArmor())
            {
                armor.l_index = i;
                armor.r_index = j;
                classifier.getArmorImg(armor);
                classifier.setArmorNum(armor);
                armors.emplace_back(armor);
            }
        }
        eraseErrorRepeatArmor(armors);
    }
    if (armors.empty())
    {
        state = ARMOR_NOT_FOUND;
        return;
    } else
    {
        state = ARMOR_FOUND;
        return;
    }
}

void ArmorDetector::setTargetArmor()
{
    if (state == ARMOR_NOT_FOUND)   targetArmor = ArmorBox();
    else if (state == ARMOR_FOUND)
    {
        ArmorBox mva = armors[0];
        for (int i = 1; i < armors.size(); i++)
        {
            if (armorCompare(armors[i], mva, lastArmor, targetNum)) mva = armors[i];
        }
        targetArmor = mva;
    }
    lastArmor = targetArmor;
}

/**
 * @brief delete error armor which is caused by the single lightbar
 * @param armors
 */
void eraseErrorRepeatArmor(vector<ArmorBox> &armors)
{
    int length = armors.size(); // todo: size_t
    vector<ArmorBox>::iterator it = armors.begin();
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (armors[i].l_index == armors[j].l_index ||
                armors[i].l_index == armors[j].r_index ||
                armors[i].r_index == armors[j].r_index ||
                armors[i].r_index == armors[j].l_index)
            {
                armors[i].getDeviationAngle() > armors[j].getDeviationAngle() ?
                it = armors.erase(it + i) : it = armors.erase(it + j);
            }
        }
    }
}

/**
 * @brief get the distance between two points
 * @param a
 * @param b
 * @return two points distance
 */
float getPointsDistance(const Point2f &a, const Point2f &b)
{
    float delta_x = a.x - b.x;
    float delta_y = a.y - b.y;
//    return sqrtf(delta_x * delta_x + delta_y *delta_y);
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

/**
 * @brief customized armor priority armorScore based on numbers
 * @param armorNum
 * @param targetNum
 * @param armorScore
 */
void setNumScore(const int &armorNum, const int &targetNum, float &armorScore)
{
    if (targetNum == 0)
    {
        if (armorNum == 1)  armorScore += 4000; // todo chance better custom score
        else if (armorNum == 2) armorScore += 3000;
        else if (armorNum == 3) armorScore += 6000;
        else if (armorNum == 4) armorScore += 5000;
        else if (armorNum == 5) armorScore += 2000;
        else if (armorNum == 6) armorScore += 1000;
    }
    if (armorNum == targetNum)  armorScore += 100000;
}

/**
 * @brief compare the two armors priority armorScore based on many factors
 * @param a_armor
 * @param b_armor
 * @param lastArmor
 * @param targetNum
 * @return a_armor greater than b_armor
 */
bool armorCompare(const ArmorBox &a_armor, const ArmorBox &b_armor, const ArmorBox &lastArmor, const int &targetNum)
{
    float a_score = 0;
    float b_score = 0;
    a_score += a_armor.armorRect.area();
    b_score += b_armor.armorRect.area();

    setNumScore(a_armor.armorNum, targetNum, a_score);
    setNumScore(b_armor.armorNum, targetNum, b_score);

    if (lastArmor.armorNum != 0)
    {
        float a_distance = getPointsDistance(a_armor.center, lastArmor.center);
        float b_distance = getPointsDistance(b_armor.center, lastArmor.center);
        a_score -= a_distance * 2;
        b_score -= b_distance * 2;
    }
    return a_score > b_score;
}
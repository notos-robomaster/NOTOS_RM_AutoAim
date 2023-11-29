#include "Armor.h"

ArmorNumClassifier::ArmorNumClassifier()
{
    svm = ml::SVM::create();
    armorImgSize = Size(40, 40);
    p = Mat();

    warpPerspective_mat = Mat(3, 3, CV_32FC1);
    dstPoints[0] = Point2f(0, 0);
    dstPoints[1] = Point2f(armorImgSize.width, 0);
    dstPoints[2] = Point2f(armorImgSize.width, armorImgSize.height);
    dstPoints[3] = Point2f(0, armorImgSize.height);
}

ArmorNumClassifier::~ArmorNumClassifier()
{}

void ArmorNumClassifier::loadSvmModel(const char *model_path, cv::Size armorImgSize)
{
    svm = StatModel::load<SVM>(model_path);
    if (svm.empty())
    {
        cerr << "SVM load error! Please check the path!" << endl;
//        cout<<"Svm load error! Please check the path!"<<endl;
        exit(0);
    }
    this->armorImgSize = armorImgSize;

    dstPoints[0] = Point2f(0, 0);
    dstPoints[1] = Point2f(armorImgSize.width, 0);
    dstPoints[2] = Point2f(armorImgSize.width, armorImgSize.height);
    dstPoints[3] = Point2f(0, armorImgSize.height);
}

void ArmorNumClassifier::loadImg(cv::Mat &srcImg)
{
    (srcImg).copyTo(warpPerspective_src);

    cvtColor(warpPerspective_src, warpPerspective_src, 6);  // CV_BGR2GRAY=6
    threshold(warpPerspective_src, warpPerspective_src, 10, 255, THRESH_BINARY);
}

void ArmorNumClassifier::getArmorImg(ArmorBox &armor)
{
    for (int i = 0; i < 4; i++)
        srcPoints[i] = armor.armorVertices[i];
    warpPerspective_mat = getPerspectiveTransform(srcPoints, dstPoints);
    warpPerspective(warpPerspective_src, warpPerspective_dst, warpPerspective_mat, armorImgSize,
                    INTER_NEAREST, BORDER_CONSTANT, Scalar(0));
    warpPerspective_dst.copyTo(armor.armorImg);
#ifdef SHOW_ARMORNUM
        imshow("Num Monitor", warpPerspective_dst);
#endif // SHOW_ARMORNUM
}

void ArmorNumClassifier::setArmorNum(ArmorBox &armor)
{
    p = armor.armorImg.reshape(1, 1);
    p.convertTo(p, CV_32FC1);

    armor.armorNum = (int) svm->predict(p);
}
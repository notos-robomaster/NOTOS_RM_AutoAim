//
// Created by LycanW on 2024/4/11.
//

#ifndef RM2025_DEV_HIKCAM_CONTROL_H
#define RM2025_DEV_HIKCAM_CONTROL_H

#include "MvCameraControl.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class HikCam{
public:

    HikCam();
    ~HikCam();

    void* handle;
    unsigned char *pData;
    bool initialize();
    bool  getVideo(Mat& frame);
    bool printCameraInfo();
    bool  startGrabbing();

private:

    bool  nRet = MV_OK;

    unsigned int  nPayloadSize;

    MV_CC_PIXEL_CONVERT_PARAM CvtParam;
    MV_CC_DEVICE_INFO_LIST stDeviceList;
    MVCC_FLOATVALUE stFloatVal;
    MV_FRAME_OUT_INFO_EX stImageInfo;
    MV_FRAME_OUT stOutFrame;

    bool  enumCamera();
    bool  createHandle();
    bool  openCamera();
    bool  setValue();
    bool  initImage();

    bool  getOneFrame();
    bool  Bayer8ToBGR(Mat& bgr_image) const;

    bool  stopGrabbing();
    bool  closeCamera();
    bool  destroyHandle();
    void  freeMemory() const;
    void  setCamera() const ;

};

#endif //RM2025_DEV_HIKCAM_CONTROL_H

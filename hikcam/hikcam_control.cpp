//
// Created by LycanW on 2024/4/11.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "hikcam_control.h"

HikCam::HikCam() {

    handle = nullptr;
    stOutFrame.pBufAddr = nullptr;

}

HikCam::~HikCam(){

    stopGrabbing();
    closeCamera();
    destroyHandle();

}
bool HikCam::initialize() {

    if (!enumCamera()) return false;
    if (!createHandle()) return false;
    if (!openCamera()) return false;
    if (!setValue()) return false;
    if (!initImage()) return false;
    setCamera();

    return true;

}

bool HikCam::enumCamera() {

    memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

    // ch:设备枚举 | en:Enum device
    nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
    if (MV_OK != nRet) {
        printf("Enum Devices fail! nRet [0x%x]\n", nRet);
        return false;
    }

    return true;

}

bool HikCam::createHandle() {

    unsigned int nIndex = 0; //自动打开唯一的HIKCam

    // ch:创建设备句柄 | en:Create handle
    nRet = MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[nIndex]);
    if (MV_OK != nRet) {
        printf("Create Handle fail! nRet [0x%x]\n", nRet);
        return false;
    }
    return true;
    
}

bool HikCam::openCamera() {
    // ch:打开设备 | en:Open device
    nRet = MV_CC_OpenDevice(handle);
    if (MV_OK != nRet) {
        printf("Open Device fail! nRet [0x%x]\n", nRet);
        return false;
    }
    return true;
}

bool HikCam::setValue() {
    nRet = MV_CC_SetEnumValue(handle, "TriggerMode", 0);
    if (MV_OK != nRet) {
        printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
        return false;
    }

    return true;
    
}

bool HikCam::initImage() {
    MVCC_INTVALUE stParam;
    memset(&stParam, 0, sizeof(MVCC_INTVALUE));
    nRet = MV_CC_GetIntValue(handle, "PayloadSize", &stParam);
    if (MV_OK != nRet) {
        printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
        return false;
    }
    nPayloadSize = stParam.nCurValue;

    // ch:初始化图像信息 | en:Init image info
    stOutFrame = {nullptr};
    memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));
    stOutFrame.pBufAddr = (unsigned char *) malloc(sizeof(unsigned char) * (nPayloadSize));
    if (nullptr == stOutFrame.pBufAddr) {
        printf("Allocate memory failed.\n");
        return false;
    }
    return true;
    
}

bool HikCam::startGrabbing(){
    // ch:开始取流 | en:Start grab image
    nRet = MV_CC_StartGrabbing(handle);
    if (MV_OK != nRet) {
        printf("Start Grabbing fail! nRet [0x%x]\n", nRet);
        return false;
    }
    return true;
}

bool HikCam::closeCamera() {
    // ch:关闭设备 | en:Close device
    nRet = MV_CC_CloseDevice(handle);
    if (MV_OK != nRet) {
        printf("ClosDevice fail! nRet [0x%x]\n", nRet);
        return false;
    }
    return true;
}

bool HikCam::stopGrabbing(){
    // ch:停止取流 | en:Stop grab image
    nRet = MV_CC_StopGrabbing(handle);
    if (MV_OK != nRet)  {
        printf("Stop Grabbing fail! nRet [0x%x]\n", nRet);
        return false;
    }

    return true;
}

bool HikCam::destroyHandle() {

    if (handle)
    {
        MV_CC_DestroyHandle(handle);
        handle = nullptr;
    }
    return true;

}

void HikCam::freeMemory()  {

    if(nullptr != stOutFrame.pBufAddr)
    {
        MV_CC_FreeImageBuffer(handle, &stOutFrame);
    }


}

void HikCam::setCamera() const   {

    //    MV_CC_SetAOIoffsetX(handle,1440);
//    MV_CC_SetAOIoffsetY(handle,1080);
//    MV_CC_SetWidth(handle,1440);
//    MV_CC_SetHeight(handle,1080);
    MV_CC_SetExposureTime(handle,1000);
    MV_CC_SetGain(handle,1.0052);
//    MV_CC_SetFrameRate(handle,250);
    MV_CC_SetGamma(handle,0);
    MV_CC_SetBalanceWhiteAuto(handle,1) ;
    MV_CC_SetGammaSelector(handle,2);

}

bool HikCam::printCameraInfo() {

    memset(&stFloatVal, 0, sizeof(MVCC_FLOATVALUE));

    MV_CC_GetExposureTime(handle, &stFloatVal);
    printf("Current ExposureTime [%f] us\n", stFloatVal.fCurValue);

    MV_CC_GetGain(handle, &stFloatVal);
    printf("Current Gain [%f] \n", stFloatVal.fCurValue);

    MV_CC_GetFrameRate(handle,&stFloatVal);
    printf("FrameRate [%f] \n", stFloatVal.fCurValue);

    MV_CC_GetGamma(handle,&stFloatVal);
    printf("Gamma [%f] \n", stFloatVal.fCurValue);
    return true;
}

bool HikCam::Bayer8ToBGR(Mat &res) const {
    Mat bgr_image;
    if (nullptr == stOutFrame.pBufAddr)
    {
        return false;
    }

    // 创建一个与Bayer RG8数据大小相匹配的Mat对象
    //    Mat src_img(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC1);
    //    memcpy(src_img.data, stOutFrame.pBufAddr, stImageInfo.nWidth * stImageInfo.nHeight);

    Mat src_img=Mat(stOutFrame.stFrameInfo.nHeight,stOutFrame.stFrameInfo.nWidth,CV_8UC1,nPayloadSize);
    memcpy(src_img.data, stOutFrame.pBufAddr, stOutFrame.stFrameInfo.nHeight * stOutFrame.stFrameInfo.nWidth);

    // 使用OpenCV的函数将Bayer RG8格式数据转换为BGR格式
    cvtColor(src_img, bgr_image, COLOR_BayerRG2RGB);
    resize(bgr_image,res,Size (),0.5,0.5,INTER_LINEAR);

    return true;
}

bool HikCam::getOneFrame() {
    MV_CC_GetImageBuffer(handle, &stOutFrame , 1000);
//    MV_CC_GetOneFrameTimeout(handle, pData, nPayloadSize, &stImageInfo, 1000);

    return true;
}

bool HikCam::getVideo(Mat& frame) {

    getOneFrame();
    Bayer8ToBGR(frame);
    freeMemory();

    return true;
}

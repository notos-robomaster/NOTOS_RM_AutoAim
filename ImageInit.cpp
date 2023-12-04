#include "MindVision/head/CameraCapture.h"
#include <opencv2/opencv.hpp>
#include "Debug.h"
#include "./General/General.h"

#ifdef USING_USB_CAMERA
cv::VideoCapture capture(0);
#endif // USING_USB_CAMERA
#ifdef VIDEO_PATH
cv::VideoCapture capture(VIDEO_PATH);
#endif // VIDEO_PATH
#ifdef TEXT_FPS
static auto timeStart = std::chrono::steady_clock::now();
#endif // TEXT_FPS

void imageInit()
{
#ifdef USING_MINDVISION
        std::cout << "MindVision Init" << std::endl;
        if (MVVideoCapture::Init() == -1)
        {
            std::cerr << "MindVision ERROR!!!" << std::endl;
            return;
        }
        MVVideoCapture::Play();
        MVVideoCapture::SetExposureTime(false, 20000);
        MVVideoCapture::SetLargeResolution(false);
        std::cout << "MindVision Finished!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
#endif // USING_MINDVISION
}

void imageUpdating()
{
#ifdef USING_MINDVISION
    MVVideoCapture::GetFastFrame(src);
#endif // USING_MINDVISION
#ifdef USING_USB_CAMERA
    capture >> src;
#endif // USING_USB_CAMERA
#ifdef VIDEO_PATH
    capture >> src;
#endif // VIDEO_PATH
}

void fpsInit()
{
#ifdef TEXT_FPS
    timeStart = std::chrono::steady_clock::now();
#endif // TEXT_FPS
}

void fpsUpdating()
{
#ifdef TEXT_FPS
    auto timePredict = std::chrono::steady_clock::now();
    double fullMs = std::chrono::duration<double, std::milli>(timePredict - timeStart).count();
    fmt::print(fmt::fg(fmt::color::gold), "FPS: {}\n", int(1000 / fullMs));
#endif // TEXT_FPS
}
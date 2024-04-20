cmake_minimum_required(VERSION 3.26)
project(NOTOS_RM_AutoAim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenCV)
find_package(fmt REQUIRED)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories("hikcam/inc")
link_directories("hikcam/lib")

add_executable(NOTOS_RM_AutoAim main.cpp
        Armor/findLights.cpp
        Armor/Armor.h
        General/General.h
        AutoAim.cpp
        Armor/ArmorDetector.cpp
        Armor/ArmorBox.cpp
        Armor/ArmorNumClassifier.cpp
        Debug.h
        Armor/LightBar.cpp
        Armor/matchArmors.cpp
        ImageInit.cpp
        MindVision/cameramain.cpp
        MindVision/head/CameraDefine.h
        MindVision/head/CameraApi.h
        MindVision/head/CameraCapture.h
        MindVision/head/CameraStatus.h
        hikcam/hikcam_control.cpp
        hikcam/hikcam_control.h
        AngleSolver/AngleSolver.cpp
        AngleSolver/AngleSolver.h
        Serial/serialport.cpp
        Serial/serialport.h
        Serial/CRC_Check.cpp
        Serial/CRC_Check.h
        Filter/Kalman.cpp
        Filter/Kalman.h
        GraphWindow/MotionDetection.cpp
        GraphWindow/MotionDetection.h
        GraphWindow/qcustomplot.cpp
        GraphWindow/qcustomplot.h
)

target_link_libraries(NOTOS_RM_AutoAim /home/oconnor/MVSDK/lib/x64/libMVSDK.so)
target_link_libraries(NOTOS_RM_AutoAim ${OpenCV_LIBRARIES} fmt::fmt pthread MvCameraControl)
target_link_libraries(NOTOS_RM_AutoAim
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::PrintSupport
)

cmake_minimum_required(VERSION 3.26)
project(autoaim_beta1)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV)
find_package(fmt REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(autoaim_beta1 main.cpp
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
        AngleSolver/AngleSolver.cpp
        AngleSolver/AngleSolver.h
        Calibration/Calibration.cpp
)

target_link_libraries(autoaim_beta1 /home/cgnb/MindVision/lib/arm64/libMVSDK.so)
target_link_libraries(autoaim_beta1 ${OpenCV_LIBRARIES} fmt::fmt pthread)
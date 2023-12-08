cmake_minimum_required(VERSION 3.26)
project(NOTOS_RM_AutoAim)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV)
find_package(fmt REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

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
        AngleSolver/AngleSolver.cpp
        AngleSolver/AngleSolver.h
        Calibration/Calibration.cpp
)

target_link_libraries(NOTOS_RM_AutoAim /home/cgnb/MindVision/lib/arm64/libMVSDK.so)
target_link_libraries(NOTOS_RM_AutoAim ${OpenCV_LIBRARIES} fmt::fmt pthread)
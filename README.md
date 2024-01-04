# NOTOS_RM_AutoAim
#### This project is the complete code for the visual function of the Guangzhou Nanfeng College Nanfeng Team in the 2024 season.

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
[![Sprache wechseln-Deutsch](https://img.shields.io/badge/Sprache%20wechseln-Deutsch-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.de.md)
---

# Repository Description

## Repository Directory
     .
     ├── AngleSolver                // Angle solver library, including angle solver class
     │ ├── AngleSolver.cpp          // Angle solution file
     │ ├── AngleSolver.h            // Angle solution header file
     ├── Armor                      // Armor plate recognition library, including armor plate recognition class
     │ ├── Armor.h                  // Armor plate identification header file
     │ ├── LightBar.cpp             // Light bar parameter file
     │ ├── ArmorBox.cpp             // Armor plate parameter file
     │ ├── ArmorNumClassifier.cpp   // Digital identification file
     │ ├── findLights.cpp           // Light bar identification file
     │ ├── matchArmors.cpp          // Armor plate matching file
     │ └── ArmorDetector.cpp        // Armor plate recognition initial file
     ├── Calibration                // Camera calibration file
     │ ├── Image                    // Image folder
     │ ├── Calibaration.cpp         // Camera calibration
     │ ├── file_images.txt          // Image path
     ├── cmake-build-debug          // Compile and generate folder
     ├── General                    // Configuration file
     │ ├── 123svm.xml               // Digital classifier
     │ ├── camera_params.xml        // Camera configuration file
     │ ├── General.h                // General header file
     ├── MindVision                 // Camera File
     │ ├── head                     // camera header file
     │ │ ├── CameraApi.h            // Camera API file
     │ │ ├── CameraCapture.h        // Camera interface file
     │ │ ├── CameraDefine.h         // Camera parameter file
     │ │ └── CameraStatus.h         // Camera definition file
     │ └── cameramain.cpp           // Camera main function
     ├── Serial                     // Serial communication library, including serial communication class
     │ ├── CRC_Check.cpp            // CRC check
     │ ├── CRC_Check.h              // CRC check header file
     │ ├── serialport.cpp           // Serial communication class
     │ └── serailport.h             // Serial communication category header file
     ├── AutoAim.cpp                // Automatic aiming class
     ├── CMakeLists.txt             // CMake project file
     ├── Debug.h                    // Debug header file
     ├── Imagelnit.cpp              // Image initialization file
     ├── LICENSE                    // License
     ├── main.cpp                   // main function
     ├── README.md                  // Project description file
     └── WatchDog.sh                // Self-starting script

# Description of arms

## Super Contest
### 1(Hero), 2(Engineer), 3(Infantry), 4(Infantry), 5(Outpost), 6(Base), 7(Sentinel)

## League match
### 1(Hero), 3(Infantry), 4(Infantry), 6(Base), 7(Sentinel)

# v2ray self-starting script
### %sudo systemctl start v2raya.service
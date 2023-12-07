# NOTOS_RM_AutoAim
#### This project is the complete code for the 2024 season vision function of the Nanfeng Team at Nanfang College Guangzhou.

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# Repository Description

## Repository Directory
    .
    ├── AngleSolver                 // Angle solver library, including the AngleSolver class
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // Armor recognition library, including the Armor class
    │   ├── Armor.h                 // Armor recognition header file
    │   ├── LightBar.cpp            // Light bar recognition header file
    │   ├── ArmorBox.cpp）          // Armor parameters file
    │   ├── ArmorNumClassifier.cpp  // Number recognition header file
    │   ├── findLights.cpp          // Light bar recognition header file
    │   ├── matchArmors.cpp         // Armor matching header file
    │   └── ArmorDetector.cpp       // Initial file for armor recognition
    ├── Calibration                 // Auto-aim library, including the AutoAim class
    │   ├── Image                   // Image folder
    │   ├── Calibaration.cpp        // Camera calibration
    ├── cmake-build-debug           // Compiled generated folder
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // Camera files
    │   ├── head                    // Camera header files
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // Camera main function
    ├── Serial                      // Serial communication library, including the Serial class
    │   ├── CRC_Check.cpp           // CRC check
    │   ├── CRC_Check.h             // CRC check header file
    │   ├── serialport.cpp          // Serial communication class
    │   └── serailport.h            // Serial communication class header file
    ├── AutoAim.cpp                 // Auto-aim class
    ├── CMakeLists.txt              // CMake project file
    ├── CodeStandard                //
    ├── Debug.h                     // Debug header file
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // Main function
    ├── LICENSE                     // License 
    ├── main.cpp                    // Main function
    ├── README.md                   // Project description file
    └── WatchDog.sh                 // Debug script
# NOTOS_RM_AutoAim
#### 本项目是广州南方学院南風战队2024赛季视觉功能完整代码

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---
# 仓库说明

## 仓库目录
    .
    ├── AngleSolver                 // 角度解算器库，包含角度解算器类
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // 装甲板识别库，包含装甲板识别类
    │   ├── Armor.h                 // 装甲板识别头文件
    │   ├── LightBar.cpp            // 灯条识别头文件
    │   ├── ArmorBox.cpp）          // 装甲板参数文件
    │   ├── ArmorNumClassifier.cpp  // 数字识别头文件
    │   ├── findLights.cpp          // 灯条识别头文件
    │   ├── matchArmors.cpp         // 装甲板匹配头文件
    │   └── ArmorDetector.cpp       // 装甲板识别初始文件
    ├── Calibration                 // 自动瞄准库，包含自动瞄准类
    │   ├── Image                   // 图像文件夹
    │   ├── Calibaration.cpp        // 相机标定
    ├── cmake-build-debug           // 编译生成文件夹
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // 相机文件
    │   ├── head                    // 相机头文件
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // 相机主函数
    ├── Serial                      // 串口通讯库，包含串口通讯类
    │   ├── CRC_Check.cpp           // CRC校验
    │   ├── CRC_Check.h             // CRC校验头文件
    │   ├── serialport.cpp          // 串口通讯类
    │   └── serailport.h            // 串口通讯类头文件
    ├── AutoAim.cpp                 // 自动瞄准类
    ├── CMakeLists.txt              // CMake工程文件
    ├── CodeStandard                //
    ├── Debug.h                     // 调试头文件
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // 主函数
    ├── LICENSE                     // 许可证 
    ├── main.cpp                    // 主函数
    ├── README.md                   // 项目说明文件
    └── WatchDog.sh                 // 调试脚本
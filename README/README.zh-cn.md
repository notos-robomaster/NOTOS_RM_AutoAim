# NOTOS_RM_AutoAim
#### 本项目为广州南方学院南风战队2024年赛季视觉功能完整代码

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# 仓库说明

## 仓库目录
    .
    ├── AngleSolver                 // 角度解算器库，包含角度解算器类
    │   ├── AngleSolver.cpp         // 角度解算文件
    │   ├── AngleSolver.h           // 角度解算头文件
    ├── Armor                       // 装甲板识别库，包含装甲板识别类
    │   ├── Armor.h                 // 装甲板识别头文件
    │   ├── LightBar.cpp            // 灯条参数文件
    │   ├── ArmorBox.cpp            // 装甲板参数文件
    │   ├── ArmorNumClassifier.cpp  // 数位辨识文件
    │   ├── findLights.cpp          // 灯条识别文件
    │   ├── matchArmors.cpp         // 装甲板匹配文件
    │   └── ArmorDetector.cpp       // 装甲板识别初始文件
    ├── Calibration                 // 相机标定文件
    │   ├── Image                   // 影像资料夹
    │   ├── Calibaration.cpp        // 相机标定
    │   ├── file_images.txt         // 影像路径
    ├── cmake-build-debug           // 编译生成资料夹
    ├── General                     // 配置文件
    │   ├── 123svm.xml              // 数位分类器
    │   ├── camera_params.xml     	// 相机配置文件
    │   ├── General.h               // 通用头文件
    ├── MindVision                  // 相机档案
    │   ├── head                    // 相机头文件
    │   │   ├── CameraApi.h         // 相机API文件
    │   │   ├── CameraCapture.h     // 相机接口文件
    │   │   ├── CameraDefine.h      // 相机参数文件
    │   │   └── CameraStatus.h      // 相机定义文件
    │   └── cameramain.cpp          // 相机主函数
    ├── Serial                      // 串列通讯库，包含串列通讯类
    │   ├── CRC_Check.cpp           // CRC校验
    │   ├── CRC_Check.h             // CRC校验头文件
    │   ├── serialport.cpp          // 串口通讯类
    │   └── serailport.h            // 串口通讯类别头文件
    ├── AutoAim.cpp                 // 自动瞄准类
    ├── CMakeLists.txt              // CMake工程文件 
    ├── Debug.h                     // 侦错头文件
    ├── Imagelnit.cpp               // 图像初始化文件
    ├── LICENSE                     // 许可证 
    ├── main.cpp                    // 主函数
    ├── README.md                   // 项目说明文件
    └── WatchDog.sh                 // 自启动脚本

# 兵种说明

## 超级对抗赛
### 1(英雄), 2(工程), 3(步兵), 4(步兵), 5(前哨战), 6(基地), 7(哨兵)

## 联盟赛
### 1(英雄), 3(步兵), 4(步兵), 6(基地), 7(哨兵)
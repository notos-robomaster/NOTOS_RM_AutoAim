# NOTOS_RM_AutoAim
#### 本項目為廣州南方學院南風戰隊2024年賽季視覺功能完整代碼

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# 倉庫說明

## 倉庫目錄
    .
    ├── AngleSolver                 // 角度解算器庫，包含角度解算器類
    │   ├── AngleSolver.cpp         // 角度解算文件
    │   ├── AngleSolver.h           // 角度解算頭文件
    ├── Armor                       // 裝甲板識別庫，包含裝甲板識別類
    │   ├── Armor.h                 // 裝甲板識別頭文件
    │   ├── LightBar.cpp            // 燈條參數文件
    │   ├── ArmorBox.cpp            // 裝甲板參數文件
    │   ├── ArmorNumClassifier.cpp  // 數位辨識文件
    │   ├── findLights.cpp          // 燈條識別文件
    │   ├── matchArmors.cpp         // 裝甲板匹配文件
    │   └── ArmorDetector.cpp       // 裝甲板識別初始文件
    ├── Calibration                 // 相機標定文件
    │   ├── Image                   // 影像資料夾
    │   ├── Calibaration.cpp        // 相機標定
    │   ├── file_images.txt         // 影像路徑
    ├── cmake-build-debug           // 編譯生成資料夾
    ├── General                     // 配置文件
    │   ├── 123svm.xml              // 數位分類器
    │   ├── camera_params.xml     	// 相機配置文件
    │   ├── General.h               // 通用頭文件
    ├── MindVision                  // 相機檔案
    │   ├── head                    // 相機頭文件
    │   │   ├── CameraApi.h         // 相機API文件
    │   │   ├── CameraCapture.h     // 相機接口文件
    │   │   ├── CameraDefine.h      // 相機參數文件
    │   │   └── CameraStatus.h      // 相機定義文件
    │   └── cameramain.cpp          // 相機主函數
    ├── Serial                      // 串列通訊庫，包含串列通訊類
    │   ├── CRC_Check.cpp           // CRC校驗
    │   ├── CRC_Check.h             // CRC校驗頭文件
    │   ├── serialport.cpp          // 串口通訊類
    │   └── serailport.h            // 串口通訊類別頭文件
    ├── AutoAim.cpp                 // 自動瞄準類
    ├── CMakeLists.txt              // CMake工程文件
    ├── Debug.h                     // 偵錯頭文件
    ├── Imagelnit.cpp               // 圖像初始化文件
    ├── LICENSE                     // 許可證 
    ├── main.cpp                    // 主函數
    ├── README.md                   // 項目說明文件
    └── WatchDog.sh                 // 自啟動腳本

# 兵種說明

## 超級對抗賽
### 1(英雄), 2(工程), 3(步兵), 4(步兵), 5(前哨戰), 6(基地), 7(哨兵)

## 聯盟賽
### 1(英雄), 3(步兵), 4(步兵), 6(基地), 7(哨兵)
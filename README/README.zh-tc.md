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
[![Sprache wechseln-Deutsch](https://img.shields.io/badge/Sprache%20wechseln-Deutsch-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.de.md)
---

# 存儲庫描述

## 存儲庫目錄
    ├── AngleSolver                 // 角度解算器庫，包含角度解算器類
    │   ├── AngleSolver.cpp         // 角度解算檔案
    │   ├── AngleSolver.h           // 角度解算頭檔
    ├── Armor                       // 裝甲板識別庫，包含裝甲板識別類
    │   ├── Armor.h                 // 裝甲板識別頭檔
    │   ├── LightBar.cpp            // 燈條參數檔
    │   ├── ArmorBox.cpp            // 裝甲板參數檔
    │   ├── ArmorNumClassifier.cpp  // 數位辨識檔
    │   ├── findLights.cpp          // 燈條識別檔
    │   ├── matchArmors.cpp         // 裝甲板匹配檔
    │   └── ArmorDetector.cpp       // 裝甲板識別初始檔
    ├── Calibration                 // 相機標定檔
    │   ├── Image                   // 影像資料夾
    │   ├── Calibaration.cpp        // 相機標定
    │   ├── file_images.txt         // 影像路徑
    ├── cmake-build-debug           // 編譯生成資料夾
    ├── General                     // 配置檔
    │   ├── 123svm.xml              // 數位分類器
    │   ├── camera_params.xml       // 相機配置檔
    │   ├── General.h               // 通用頭檔
    ├── MindVision                  // 相機檔案
    │   ├── head                    // 相機頭檔
    │   │   ├── CameraApi.h         // 相機API檔
    │   │   ├── CameraCapture.h     // 相機介面檔
    │   │   ├── CameraDefine.h      // 相機參數檔
    │   │   └── CameraStatus.h      // 相機定義檔
    │   └── cameramain.cpp          // 相機主函數
    ├── README                      // 說明檔案
    │   ├── README.de.md            // 德語說明檔案
    │   ├── README.es.md            // 西班牙語說明檔案
    │   ├── README.fr.md            // 法語說明檔案
    │   ├── README.jp.md            // 日語說明檔案
    │   ├── README.ru.md            // 俄語說明檔案
    │   ├── README.zh-cn.md         // 簡中說明檔案
    │   └── README.zh-tc.md         // 繁中說明檔案
    ├── Serial                      // 串列通訊庫，包含串列通訊類
    │   ├── CRC_Check.cpp           // CRC校驗
    │   ├── CRC_Check.h             // CRC校驗頭檔
    │   ├── serialport.cpp          // 串口通訊類
    │   └── serailport.h            // 串口通訊類別頭檔
    ├── AutoAim.cpp                 // 自動瞄準類
    ├── CMakeLists.txt              // CMake工程檔 
    ├── Debug.h                     // 偵錯頭檔
    ├── Imagelnit.cpp               // 圖像初始化檔
    ├── LICENSE                     // 許可證 
    ├── main.cpp                    // 主函數
    ├── README.md                   // 英語說明檔案
    └── WatchDog.sh                 // 自啟動腳本


# 兵種說明

## 超級對抗賽
### 1(英雄), 2(工程), 3(步兵), 4(步兵), 5(前哨戰), 6(基地), 7(哨兵)

## 聯盟賽
### 1(英雄), 3(步兵), 4(步兵), 6(基地), 7(哨兵)

# v2ray 自啟動腳本
### %sudo systemctl start v2raya.service
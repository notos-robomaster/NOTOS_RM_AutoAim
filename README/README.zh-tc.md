# NOTOS_RM_AutoAim
本項目為廣州南方學院南風戰隊2024年賽季視覺功能完整代碼

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README.md)
---

## 存儲庫描述
存儲庫目錄

    .
    ├── AngleSolver                // 角度解算器庫，包含角度解算器類
    │ ├── AngleSolver.cpp          // 角度解算檔案
    │ └── AngleSolver.h            // 角度解算頭檔
    ├── Armor                      // 裝甲板識別庫，包含裝甲板識別類
    │ ├── Armor.h                  // 裝甲板識別頭檔
    │ ├── LightBar.cpp             // 燈條參數檔
    │ ├── ArmorBox.cpp             // 裝甲板參數檔
    │ ├── ArmorNumClassifier.cpp   // 數位辨識檔
    │ ├── findLights.cpp           // 燈條識別檔
    │ ├── matchArmors.cpp          // 裝甲板匹配檔
    │ └── ArmorDetector.cpp        // 裝甲板識別初始檔
    ├── Calibration                // 相機標定檔
    │ ├── Image                    // 影像資料夾
    │ ├── Calibaration.cpp         // 相機標定
    │ └── file_images.txt          // 影像路徑
    ├── cmake-build-debug          // 編譯生成資料夾
    ├── Filter                     // 濾波器解算
    │ ├── Kalman.cpp               // 卡爾曼解算檔案
    │ └── Kalman.cpp               // 卡爾曼解算頭檔
    ├── General                    // 配置檔
    │ ├── 123svm.xml               // 數位分類器
    │ ├── camera_params.xml        // 相機配置檔
    │ └── General.h                // 通用頭檔
    ├── GraphWindow                // 圖表窗口
    │ ├── MotionDetection.cpp      // 運動偵測檔案
    │ ├── MotionDetection.h        // 運動偵測頭檔
    │ ├── qcustomplot.cpp          // qt繪圖配置檔案
    │ └── qcustomplot.h            // qt繪圖配置頭檔
    ├── MindVision                 // 相機檔案
    │ ├── head                     // 相機頭檔
    │ │ ├── CameraApi.h            // 相機API檔
    │ │ ├── CameraCapture.h        // 相機介面檔
    │ │ ├── CameraDefine.h         // 相機參數檔
    │ │ └── CameraStatus.h         // 相機定義檔
    │ └── cameramain.cpp           // 相機主函數
    ├── README                     // 說明檔案
    │ ├── README.zh-cn.md          // 簡中說明檔案
    │ └── README.zh-tc.md          // 繁中說明檔案
    ├── Serial                     // 串列通訊庫，包含串列通訊類
    │ ├── CRC_Check.cpp            // CRC校驗
    │ ├── CRC_Check.h              // CRC校驗頭檔
    │ ├── serialport.cpp           // 串口通訊類
    │ └── serailport.h             // 串口通訊類別頭檔
    ├── AutoAim.cpp                // 自動瞄準類
    ├── CMakeLists.txt             // CMake工程檔 
    ├── Debug.h                    // 偵錯頭檔
    ├── Imagelnit.cpp              // 圖像初始化檔
    ├── LICENSE                    // 許可證 
    ├── main.cpp                   // 主函數
    ├── README.md                  // 英語說明檔案
    └── WatchDog.sh                // 自啟動腳本

## 與stm32的通訊協議
Mini PC 傳送:

| Byte0 | Byte1    | Byte2 | Byte3 | Byte4 | Byte5 | Byte6 | Byte7 |
|-------|----------|----------------|-------------| -------------|---------------|-----------|-------|
| 0x16 | 是否辨識到裝甲板 | yaw軸角度標誌位元 | yaw角度資料位元 | pitch軸角度標誌位元 | yaw角度資料位元 | CRC校驗位元 | 0xFE |

Mini PC 接收:

| Byte0 | Byte1 | Byte2 | Byte3 |
|------|-------|-------|---------|
| 是否開啟卡爾曼 | 裝甲板選擇 | 裝甲板顏色 | 0x03 |

## 圖表視窗
運動偵測處理點擊事件

| 滑鼠左鍵 | 滑鼠中鍵 | 滑鼠右鍵 |
|------|--------|--------|
| 標定點 | 繼續繪製圖表 | 暫停繪製圖表 |

## 兵種說明

### 超級對抗賽
1(英雄), 2(工程), 3(步兵), 4(步兵), 5(前哨戰), 6(基地), 7(哨兵)

### 聯盟賽
1(英雄), 3(步兵), 4(步兵), 6(基地), 7(哨兵)

## v2ray 自啟動腳本
$sudo systemctl start v2raya.service

## 打開串口腳本
$sudo chmod 777 /dev/ttyUSB0
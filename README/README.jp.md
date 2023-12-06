# NOTOS_RM_AutoAim
#### このプロジェクトは南風戦隊の南方学院2024シーズンのビジョン機能の完全なコードです。

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# リポジトリの説明

## リポジトリディレクトリ
    .
    ├── AngleSolver                 // 角度ソルバーライブラリ、AngleSolverクラスを含む
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // 装甲板認識ライブラリ、Armorクラスを含む
    │   ├── Armor.h                 // 装甲板認識ヘッダーファイル
    │   ├── LightBar.cpp            // ライトバー認識ヘッダーファイル
    │   ├── ArmorBox.cpp）          // 装甲板パラメーターファイル
    │   ├── ArmorNumClassifier.cpp  // 数字認識ヘッダーファイル
    │   ├── findLights.cpp          // ライトバー認識ヘッダーファイル
    │   ├── matchArmors.cpp         // 装甲板マッチングヘッダーファイル
    │   └── ArmorDetector.cpp       // 装甲板認識初期ファイル
    ├── Calibration                 // オートエイムライブラリ、AutoAimクラスを含む
    │   ├── Image                   // 画像フォルダ
    │   ├── Calibaration.cpp        // カメラキャリブレーション
    ├── cmake-build-debug           // コンパイル生成フォルダ
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // カメラファイル
    │   ├── head                    // カメラヘッダーファイル
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // カメラメイン機能
    ├── Serial                      // シリアル通信ライブラリ、Serialクラスを含む
    │   ├── CRC_Check.cpp           // CRCチェック
    │   ├── CRC_Check.h             // CRCチェックヘッダーファイル
    │   ├── serialport.cpp          // シリアル通信クラス
    │   └── serailport.h            // シリアル通信クラスヘッダーファイル
    ├── AutoAim.cpp                 // オートエイムクラス
    ├── CMakeLists.txt              // CMakeプロジェクトファイル
    ├── CodeStandard                //
    ├── Debug.h                     // デバッグヘッダーファイル
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // メイン機能
    ├── LICENSE                     // ライセンス 
    ├── main.cpp                    // メイン機能
    ├── README.md                   // プロジェクト説明ファイル
    └── WatchDog.sh                 // デバッグスクリプト
# NOTOS_RM_AutoAim
#### このプロジェクトは、2024 年シーズンの広州南風大学南風チームの視覚機能の完全なコードです。

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

# 倉庫の説明

## 倉庫ディレクトリ
    ├── AngleSolver                 // 角度計算ライブラリ，角度計算クラスを含む
    │   ├── AngleSolver.cpp         // 角度計算ファイル
    │   ├── AngleSolver.h           // 角度計算ヘッダーファイル
    ├── Armor                       // 装甲板認識ライブラリ，装甲板認識クラスを含む
    │   ├── Armor.h                 // 装甲板認識ヘッダーファイル
    │   ├── LightBar.cpp            // ライトバーのパラメーターファイル
    │   ├── ArmorBox.cpp            // 装甲板のパラメーターファイル
    │   ├── ArmorNumClassifier.cpp  // 数字識別ファイル
    │   ├── findLights.cpp          // ライトバー認識ファイル
    │   ├── matchArmors.cpp         // 装甲板マッチングファイル
    │   └── ArmorDetector.cpp       // 装甲板認識初期ファイル
    ├── Calibration                 // カメラキャリブレーションファイル
    │   ├── Image                   // 画像データフォルダ
    │   ├── Calibaration.cpp        // カメラキャリブレーション
    │   ├── file_images.txt         // 画像のパス
    ├── cmake-build-debug           // コンパイル生成データフォルダ
    ├── General                     // 設定ファイル
    │   ├── 123svm.xml              // 数字分類器
    │   ├── camera_params.xml     	// カメラ設定ファイル
    │   ├── General.h               // 一般的なヘッダーファイル
    ├── MindVision                  // カメラファイル
    │   ├── head                    // カメラヘッダーファイル
    │   │   ├── CameraApi.h         // カメラAPIファイル
    │   │   ├── CameraCapture.h     // カメラインタフェースファイル
    │   │   ├── CameraDefine.h      // カメラパラメーターファイル
    │   │   └── CameraStatus.h      // カメラ定義ファイル
    │   └── cameramain.cpp          // カメラメインファンクション
    ├── README                      // 説明ファイル
    │   ├── README.de.md            // ドイツ語の説明ファイル
    │   ├── README.es.md            // スペイン語の説明ファイル
    │   ├── README.fr.md            // フランス語の説明ファイル
    │   ├── README.jp.md            // 日本語の説明ファイル
    │   ├── README.ru.md            // ロシア語の説明ファイル
    │   ├── README.zh-cn.md         // 簡体字中国語の説明ファイル
    │   └── README.zh-tc.md         // 繁体字中国語の説明ファイル
    ├── Serial                      // シリアル通信ライブラリ，シリアル通信クラスを含む
    │   ├── CRC_Check.cpp           // CRCチェック
    │   ├── CRC_Check.h             // CRCチェックヘッダーファイル
    │   ├── serialport.cpp          // シリアル通信クラス
    │   └── serailport.h            // シリアル通信クラスのヘッダーファイル
    ├── AutoAim.cpp                 // 自動照準クラス
    ├── CMakeLists.txt              // CMakeプロジェクトファイル
    ├── Debug.h                     // デバッグヘッダーファイル
    ├── Imagelnit.cpp               // 画像の初期化ファイル
    ├── LICENSE                     // ライセンス
    ├── main.cpp                    // メインファンクション
    ├── README.md                   // 英語の説明ファイル
    └── WatchDog.sh                 // 自動起動スクリプト

# 武器の説明

## スーパーコンテスト
### 1(ヒーロー)、2(エンジニア)、3(歩兵)、4(歩兵)、5(前哨基地)、6(基地)、7(センチネル)

## リーグ戦
### 1(ヒーロー)、3(歩兵)、4(歩兵)、6(基地)、7(センチネル)
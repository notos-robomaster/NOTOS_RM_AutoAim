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
---

# 倉庫の説明

## 倉庫ディレクトリ
     。
     §── AngleSolver                // 角度ソルバー ライブラリ（角度ソルバー クラスを含む）
     │ §── AngleSolver.cpp          // 角度解ファイル
     │ §── AngleSolver.h            // 角度解ヘッダファイル
     §── 装甲                        // 装甲板認識ライブラリ（装甲板認識クラスを含む）
     │ §── Armor.h                  // 装甲板識別ヘッダファイル
     │ §── LightBar.cpp             // ライトバーパラメータファイル
     │ §── ArmorBox.cpp             // 装甲板パラメータファイル
     │ §── ArmorNumClassifier.cpp   // デジタル識別ファイル
     │ §── findLights.cpp           // ライトバー識別ファイル
     │ §── matchArmors.cpp          // 装甲板マッチングファイル
     │ └─ ArmorDetector.cpp         // 装甲板認識初期ファイル
     §── Calibration                // カメラキャリブレーションファイル
     │ §── Image                    // 画像フォルダ
     │ §── Calibaration.cpp         // カメラのキャリブレーション
     │ §── file_images.txt          // 画像パス
     §── cmake-build-debug          // コンパイルしてフォルダーを生成
     §── General                    // 設定ファイル
     │ §── 123svm.xml               // デジタル分類器
     │ §── Camera_params.xml        // カメラ設定ファイル
     │ §── General.h                // 一般ヘッダファイル
     §── MindVision                 // カメラファイル
     │ §── head                     // カメラヘッダファイル
     │ │ §── CameraApi.h            // カメラ API ファイル
     │ │ §── CameraCapture.h        // カメラインターフェースファイル
     │ │ §── CameraDefine.h         // カメラパラメータファイル
     │ │ └─ CameraStatus.h          // カメラ定義ファイル
     │ └─ Cameramain.cpp            // カメラメイン関数
     §── Serial                     // シリアル通信クラスを含むシリアル通信ライブラリ
     │ §── CRC_Check.cpp            // CRCチェック
     │ §── CRC_Check.h              // CRCチェックヘッダファイル
     │ §──serialport.cpp            // シリアル通信クラス
     │ └── serailport.h             // シリアル通信カテゴリヘッダファイル
     §── AutoAim.cpp                // 自動照準クラス
     §── CMakeLists.txt             // CMake プロジェクト ファイル
     §── Debug.h                    // デバッグヘッダーファイル
     §── Imagelnit.cpp              // イメージ初期化ファイル
     §── LICENSE                    // ライセンス
     §── main.cpp                   // メイン関数
     §── README.md                  // プロジェクト説明ファイル
     └── WatchDog.sh                // 自己起動スクリプト

# 武器の説明

## スーパーコンテスト
### 1(ヒーロー)、2(エンジニア)、3(歩兵)、4(歩兵)、5(前哨基地)、6(基地)、7(センチネル)

## リーグ戦
### 1(ヒーロー)、3(歩兵)、4(歩兵)、6(基地)、7(センチネル)
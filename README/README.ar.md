# NOTOS_RM_AutoAim
#### هذا المشروع هو الشيفرة البرمجية الكاملة لوظيفة الرؤية لفريق Nanfeng في جامعة جنوب الصين لموسم 2024.

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# وصف المستودع

## دليل المستودع
    .
    ├── AngleSolver                 // مكتبة حل الميل، تحتوي على فئة AngleSolver
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // مكتبة التعرف على الدروع، تحتوي على فئة Armor
    │   ├── Armor.h                 // ملف رأس التعرف على الدروع
    │   ├── LightBar.cpp            // ملف رأس التعرف على الشريط الضوء
    │   ├── ArmorBox.cpp）          // ملف معلمات الدرع
    │   ├── ArmorNumClassifier.cpp  // ملف رأس التعرف على الأرقام
    │   ├── findLights.cpp          // ملف رأس التعرف على الشريط الضوء
    │   ├── matchArmors.cpp         // ملف رأس المطابقة للدروع
    │   └── ArmorDetector.cpp       // ملف البداية للتعرف على الدروع
    ├── Calibration                 // مكتبة الهدف التلقائي، تحتوي على فئة AutoAim
    │   ├── Image                   // مجلد الصور
    │   ├── Calibaration.cpp        // معايرة الكاميرا
    ├── cmake-build-debug           // مجلد الإنشاء المترجم
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // ملفات الكاميرا
    │   ├── head                    // ملفات رأس الكاميرا
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // الدالة الرئيسية للكاميرا
    ├── Serial                      // مكتبة الاتصال المتسلسل، تحتوي على فئة Serial
    │   ├── CRC_Check.cpp           // التحقق من CRC
    │   ├── CRC_Check.h             // ملف رأس التحقق من CRC
    │   ├── serialport.cpp          // فئة الاتصال المتسلسل
    │   └── serailport.h            // ملف رأس فئة الاتصال المتسلسل
    ├── AutoAim.cpp                 // فئة الهدف التلقائي
    ├── CMakeLists.txt              // ملف مشروع CMake
    ├── CodeStandard                //
    ├── Debug.h                     // ملف رأس التصحيح
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // الدالة الرئيسية
    ├── LICENSE                     // رخصة 
    ├── main.cpp                    // الدالة الرئيسية
    ├── README.md                   // ملف وصف المشروع
    └── WatchDog.sh                 // نص تصحيح
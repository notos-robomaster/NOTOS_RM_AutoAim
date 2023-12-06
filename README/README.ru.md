# NOTOS_RM_AutoAim
#### Этот проект представляет собой полный код для функции зрения команды Nanfeng в Южно-Китайском университете на сезоне 2024 года.

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---
# Описание репозитория

## Директория репозитория
    .
    ├── AngleSolver                 // Библиотека решения углов, включающая класс AngleSolver
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // Библиотека распознавания брони, включающая класс Armor
    │   ├── Armor.h                 // Заголовочный файл распознавания брони
    │   ├── LightBar.cpp            // Заголовочный файл распознавания световой полосы
    │   ├── ArmorBox.cpp）          // Файл параметров брони
    │   ├── ArmorNumClassifier.cpp  // Заголовочный файл распознавания цифр
    │   ├── findLights.cpp          // Заголовочный файл распознавания световой полосы
    │   ├── matchArmors.cpp         // Заголовочный файл сопоставления брони
    │   └── ArmorDetector.cpp       // Начальный файл для распознавания брони
    ├── Calibration                 // Библиотека автоматического прицеливания, включающая класс AutoAim
    │   ├── Image                   // Папка с изображениями
    │   ├── Calibaration.cpp        // Калибровка камеры
    ├── cmake-build-debug           // Папка, созданная при компиляции
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // Файлы камеры
    │   ├── head                    // Заголовочные файлы камеры
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // Основная функция камеры
    ├── Serial                      // Библиотека последовательной связи, включающая класс Serial
    │   ├── CRC_Check.cpp           // Проверка CRC
    │   ├── CRC_Check.h             // Заголовочный файл проверки CRC
    │   ├── serialport.cpp          // Класс последовательной связи
    │   └── serailport.h            // Заголовочный файл класса последовательной связи
    ├── AutoAim.cpp                 // Класс автоматического прицеливания
    ├── CMakeLists.txt              // Файл проекта CMake
    ├── CodeStandard                //
    ├── Debug.h                     // Заголовочный файл отладки
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // Основная функция
    ├── LICENSE                     // Лицензия 
    ├── main.cpp                    // Основная функция
    ├── README.md                   // Файл описания проекта
    └── WatchDog.sh                 // Скрипт отладки
# NOTOS_RM_AutoAim
#### Этот проект представляет собой полный код визуальной функции команды Наньфэн колледжа Гуанчжоу Наньфэн в сезоне 2024 года.

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

# Описание склада

## Каталог склада
    ├── AngleSolver                 // Библиотека для решения углов, включая класс решения углов
    │   ├── AngleSolver.cpp         // Файл решения углов
    │   ├── AngleSolver.h           // Заголовочный файл решения углов
    ├── Armor                       // Библиотека распознавания брони, включая класс распознавания брони
    │   ├── Armor.h                 // Заголовочный файл распознавания брони
    │   ├── LightBar.cpp            // Файл параметров световых полос
    │   ├── ArmorBox.cpp            // Файл параметров брони
    │   ├── ArmorNumClassifier.cpp  // Файл распознавания цифр
    │   ├── findLights.cpp          // Файл распознавания световых полос
    │   ├── matchArmors.cpp         // Файл сопоставления брони
    │   └── ArmorDetector.cpp       // Исходный файл распознавания брони
    ├── Calibration                 // Файл калибровки камеры
    │   ├── Image                   // Папка с изображениями
    │   ├── Calibaration.cpp        // Калибровка камеры
    │   ├── file_images.txt         // Пути изображений
    ├── cmake-build-debug           // Папка с компилированными данными
    ├── General                     // Файлы конфигурации
    │   ├── 123svm.xml              // Классификатор цифр
    │   ├── camera_params.xml     	// Файл конфигурации камеры
    │   ├── General.h               // Общий заголовочный файл
    ├── MindVision                  // Файлы камеры
    │   ├── head                    // Заголовочные файлы камеры
    │   │   ├── CameraApi.h         // Файл API камеры
    │   │   ├── CameraCapture.h     // Файл интерфейса камеры
    │   │   ├── CameraDefine.h      // Файл параметров камеры
    │   │   └── CameraStatus.h      // Файл определения камеры
    │   └── cameramain.cpp          // Основной файл камеры
    ├── README                      // Файл описания
    │   ├── README.de.md            // Файл описания на немецком языке
    │   ├── README.es.md            // Файл описания на испанском языке
    │   ├── README.fr.md            // Файл описания на французском языке
    │   ├── README.jp.md            // Файл описания на японском языке
    │   ├── README.ru.md            // Файл описания на русском языке
    │   ├── README.zh-cn.md         // Файл описания на китайском (упрощенном) языке
    │   └── README.zh-tc.md         // Файл описания на китайском (традиционном) языке
    ├── Serial                      // Библиотека последовательной связи, включая класс последовательной связи
    │   ├── CRC_Check.cpp           // Проверка CRC
    │   ├── CRC_Check.h             // Заголовочный файл проверки CRC
    │   ├── serialport.cpp          // Класс последовательной связи
    │   └── serailport.h            // Заголовочный файл класса последовательной связи
    ├── AutoAim.cpp                 // Класс автоматического прицеливания
    ├── CMakeLists.txt              // Файл проекта CMake
    ├── Debug.h                     // Заголовочный файл отладки
    ├── Imagelnit.cpp               // Файл инициализации изображений
    ├── LICENSE                     // Лицензия
    ├── main.cpp                    // Основная функция
    ├── README.md                   // Файл описания на английском языке
    └── WatchDog.sh                 // Сценарий автозапуска

# Описание оружия

## Суперконкурс
### 1(Герой), 2(Инженер), 3(Пехота), 4(Пехота), 5(Аванпост), 6(База), 7(Страж)

## Матч лиги
### 1(Герой), 3(Пехота), 4(Пехота), 6(База), 7(Страж)

# Самозапускающийся скрипт v2ray
### %sudo systemctl start v2raya.service
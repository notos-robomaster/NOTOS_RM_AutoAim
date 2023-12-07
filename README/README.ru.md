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
---

# Описание склада

## Каталог склада
     .
     ├── AngleSolver                // Библиотека решателя углов, включая класс решателя углов
     │ ├── AngleSolver.cpp          // Файл решения угла
     │ ├── AngleSolver.h            // Заголовочный файл решения угла
     ├── Armor                      // Библиотека распознавания бронеплит, включая класс распознавания бронеплит
     │ ├── Armor.h                  // Заголовочный файл идентификации бронепластины
     │ ├── LightBar.cpp             // Файл параметров световой панели
     │ ├── ArmorBox.cpp             // Файл параметров бронепластины
     │ ├── ArmorNumClassifier.cpp   // Файл цифровой идентификации
     │ ├── findLights.cpp           // Файл идентификации световой панели
     │ ├── matchArmors.cpp          // Файл соответствия броневых пластин
     │ └── ArmorDetector.cpp        // Исходный файл распознавания бронеплит
     ├── Calibration                // Файл калибровки камеры
     │ ├── Image                    // Папка с изображениями
     │ ├── Calibaration.cpp         // Калибровка камеры
     │ ├── file_images.txt          // Путь к изображению
     ├── cmake-build-debug          // Компилируем и создаем папку
     ├── General                    // Файл конфигурации
     │ ├── 123svm.xml               // Цифровой классификатор
     │ ├── camera_params.xml        // Файл конфигурации камеры
     │ ├── General.h                // Файл общего заголовка
     ├── MindVision                 // Файл камеры
     │ ├── head                     // файл заголовка камеры
     │ │ ├── CameraApi.h            // Файл API камеры
     │ │ ├── CameraCapture.h        // Файл интерфейса камеры
     │ │ ├── CameraDefine.h         // Файл параметров камеры
     │ │ └── CameraStatus.h         // Файл определения камеры
     │ └── cameramain.cpp           // Основная функция камеры
     ├── Serial                     // Библиотека последовательной связи, включая класс последовательной связи
     │ ├── CRC_Check.cpp            // проверка CRC
     │ ├── CRC_Check.h              // файл заголовка проверки CRC
     │ ├── Serialport.cpp           // Класс последовательной связи
     │ └── serailport.h             // Файл заголовка категории последовательной связи
     ├── AutoAim.cpp                // Класс автоматического прицеливания
     ├── CMakeLists.txt             // файл проекта CMake
     ├── Debug.h                    // Файл заголовка отладки
     ├── Imagelnit.cpp              // Файл инициализации изображения
     ├── LICENSE                    // Лицензия
     ├── main.cpp                   // основная функция
     ├── README.md                  // Файл описания проекта
     └── WatchDog.sh                // Самозапускающийся скрипт

# Описание оружия

## Суперконкурс
### 1(Герой), 2(Инженер), 3(Пехота), 4(Пехота), 5(Аванпост), 6(База), 7(Страж)

## Матч лиги
### 1(Герой), 3(Пехота), 4(Пехота), 6(База), 7(Страж)
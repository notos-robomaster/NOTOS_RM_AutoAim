# NOTOS_RM_AutoAim
#### Este proyecto es el código completo para la función de visión de la temporada 2024 del equipo Nanfeng en la Universidad de Tecnología del Sur de China.

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# Descripción del Repositorio

## Directorio del Repositorio
    .
    ├── AngleSolver                 // Biblioteca de resolución de ángulos, que incluye la clase AngleSolver
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // Biblioteca de reconocimiento de armaduras, que incluye la clase Armor
    │   ├── Armor.h                 // Archivo de encabezado de reconocimiento de armaduras
    │   ├── LightBar.cpp            // Archivo de encabezado de reconocimiento de barras de luz
    │   ├── ArmorBox.cpp）          // Archivo de parámetros de armadura
    │   ├── ArmorNumClassifier.cpp  // Archivo de encabezado de reconocimiento de números
    │   ├── findLights.cpp          // Archivo de encabezado de reconocimiento de barras de luz
    │   ├── matchArmors.cpp         // Archivo de encabezado de coincidencia de armaduras
    │   └── ArmorDetector.cpp       // Archivo inicial para el reconocimiento de armaduras
    ├── Calibration                 // Biblioteca de apuntado automático, que incluye la clase AutoAim
    │   ├── Image                   // Carpeta de imágenes
    │   ├── Calibaration.cpp        // Calibración de la cámara
    ├── cmake-build-debug           // Carpeta generada por compilación
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // Archivos de la cámara
    │   ├── head                    // Archivos de encabezado de la cámara
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // Función principal de la cámara
    ├── Serial                      // Biblioteca de comunicación serie, que incluye la clase Serial
    │   ├── CRC_Check.cpp           // Verificación CRC
    │   ├── CRC_Check.h             // Archivo de encabezado de verificación CRC
    │   ├── serialport.cpp          // Clase de comunicación serie
    │   └── serailport.h            // Archivo de encabezado de la clase de comunicación serie
    ├── AutoAim.cpp                 // Clase de apuntado automático
    ├── CMakeLists.txt              // Archivo de proyecto CMake
    ├── CodeStandard                //
    ├── Debug.h                     // Archivo de encabezado de depuración
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // Función principal
    ├── LICENSE                     // Licencia 
    ├── main.cpp                    // Función principal
    ├── README.md                   // Archivo de descripción del proyecto
    └── WatchDog.sh                 // Script de depuración
# NOTOS_RM_AutoAim
#### Este proyecto es el código completo para la función visual del equipo Nanfeng de Guangzhou Nanfeng College en la temporada 2024.

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

# Descripción del almacén

## Directorio de almacén
    ├── AngleSolver                 // Biblioteca de resolución de ángulos, que incluye la clase de resolución de ángulos
    │   ├── AngleSolver.cpp         // Archivo de resolución de ángulos
    │   ├── AngleSolver.h           // Archivo de encabezado de resolución de ángulos
    ├── Armor                       // Biblioteca de reconocimiento de armaduras, que incluye la clase de reconocimiento de armaduras
    │   ├── Armor.h                 // Archivo de encabezado de reconocimiento de armaduras
    │   ├── LightBar.cpp            // Archivo de parámetros de barras de luz
    │   ├── ArmorBox.cpp            // Archivo de parámetros de armaduras
    │   ├── ArmorNumClassifier.cpp  // Archivo de reconocimiento de dígitos
    │   ├── findLights.cpp          // Archivo de reconocimiento de barras de luz
    │   ├── matchArmors.cpp         // Archivo de emparejamiento de armaduras
    │   └── ArmorDetector.cpp       // Archivo inicial de reconocimiento de armaduras
    ├── Calibration                 // Archivo de calibración de la cámara
    │   ├── Image                   // Carpeta de datos de imágenes
    │   ├── Calibaration.cpp        // Calibración de la cámara
    │   ├── file_images.txt         // Rutas de las imágenes
    ├── cmake-build-debug           // Carpeta de datos de compilación generada
    ├── General                     // Archivos de configuración
    │   ├── 123svm.xml              // Clasificador de dígitos
    │   ├── camera_params.xml     	// Archivo de configuración de la cámara
    │   ├── General.h               // Archivo de encabezado general
    ├── MindVision                  // Archivo de configuración de la cámara
    │   ├── head                    // Archivo de encabezado de la cámara
    │   │   ├── CameraApi.h         // Archivo de API de la cámara
    │   │   ├── CameraCapture.h     // Archivo de interfaz de la cámara
    │   │   ├── CameraDefine.h      // Archivo de parámetros de la cámara
    │   │   └── CameraStatus.h      // Archivo de definiciones de la cámara
    │   └── cameramain.cpp          // Archivo principal de la cámara
    ├── README                      // Archivo de descripción
    │   ├── README.de.md            // Archivo de descripción en alemán
    │   ├── README.es.md            // Archivo de descripción en español
    │   ├── README.fr.md            // Archivo de descripción en francés
    │   ├── README.jp.md            // Archivo de descripción en japonés
    │   ├── README.ru.md            // Archivo de descripción en ruso
    │   ├── README.zh-cn.md         // Archivo de descripción en chino simplificado
    │   └── README.zh-tc.md         // Archivo de descripción en chino tradicional
    ├── Serial                      // Biblioteca de comunicación serial, que incluye la clase de comunicación serial
    │   ├── CRC_Check.cpp           // Verificación de CRC
    │   ├── CRC_Check.h             // Archivo de encabezado de verificación de CRC
    │   ├── serialport.cpp          // Clase de comunicación serial
    │   └── serailport.h            // Archivo de encabezado de la clase de comunicación serial
    ├── AutoAim.cpp                 // Clase de puntería automática
    ├── CMakeLists.txt              // Archivo de proyecto de CMake
    ├── Debug.h                     // Archivo de encabezado de depuración
    ├── Imagelnit.cpp               // Archivo de inicialización de imágenes
    ├── LICENSE                     // Licencia
    ├── main.cpp                    // Función principal
    ├── README.md                   // Archivo de descripción en inglés
    └── WatchDog.sh                 // Script de inicio automático

# Descripción de armas

## Súper Concurso
### 1 (Héroe), 2 (Ingeniero), 3 (Infantería), 4 (Infantería), 5 (Puesto avanzado), 6 (Base), 7 (Centinela)

## partido de liga
### 1(Héroe), 3(Infantería), 4(Infantería), 6(Base), 7(Centinela)

# script de inicio automático v2ray
### %sudo systemctl start v2raya.service
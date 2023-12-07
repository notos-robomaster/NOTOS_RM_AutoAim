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
---

# Descripción del almacén

## Directorio de almacén
     .
     ├── AngleSolver                // Biblioteca de resolución de ángulos, incluida la clase de resolución de ángulos
     │ ├── AngleSolver.cpp          // Archivo de solución de ángulo
     │ ├── AngleSolver.h            // Archivo de encabezado de solución de ángulo
     ├── Armor                      // Biblioteca de reconocimiento de placas de armadura, incluida la clase de reconocimiento de placas de armadura
     │ ├── Armor.h                  // Archivo de encabezado de identificación de placa de armadura
     │ ├── LightBar.cpp             // Archivo de parámetros de la barra de luces
     │ ├── ArmorBox.cpp             // Archivo de parámetros de placa de armadura
     │ ├── ArmorNumClassifier.cpp   // Archivo de identificación digital
     │ ├── findLights.cpp           // Archivo de identificación de la barra de luces
     │ ├── matchArmors.cpp          // Archivo de coincidencia de placas de armadura
     │ └── ArmorDetector.cpp        // Archivo inicial de reconocimiento de placas de armadura
     ├── Calibration                // Archivo de calibración de la cámara
     │ ├── Image                    // Carpeta de imágenes
     │ ├── Calibaration.cpp         // Calibración de la cámara
     │ ├── file_images.txt          // Ruta de la imagen
     ├── cmake-build-debug          // Compila y genera carpeta
     ├── General                    // Archivo de configuración
     │ ├── 123svm.xml               // Clasificador digital
     │ ├── camera_params.xml        // Archivo de configuración de la cámara
     │ ├── General.h                // Archivo de encabezado general
     ├── MindVision                 // Archivo de cámara
     │ ├── head                     // archivo de encabezado de cámara
     │ │ ├── CameraApi.h            // Archivo API de cámara
     │ │ ├── CameraCapture.h        // Archivo de interfaz de la cámara
     │ │ ├── CameraDefine.h         // Archivo de parámetros de la cámara
     │ │ └── CameraStatus.h         // Archivo de definición de cámara
     │ └── cameramain.cpp           // Función principal de la cámara
     ├── Serial                     // Biblioteca de comunicación en serie, incluida la clase de comunicación en serie
     │ ├── CRC_Check.cpp            // verificación CRC
     │ ├── CRC_Check.h              // archivo de encabezado de verificación CRC
     │ ├── serialport.cpp           // Clase de comunicación serie
     │ └── serailport.h             // Archivo de encabezado de categoría de comunicación serie
     ├── AutoAim.cpp                // Clase de puntería automática
     ├── CMakeLists.txt             // Archivo de proyecto CMake
     ├── Debug.h                    // Archivo de encabezado de depuración
     ├── Imagelnit.cpp              // Archivo de inicialización de imagen
     ├── LICENSE                    // Licencia
     ├── main.cpp                   // función principal
     ├── README.md                  // Archivo de descripción del proyecto
     └── WatchDog.sh                // Script de inicio automático

# Descripción de armas

## Súper Concurso
### 1 (Héroe), 2 (Ingeniero), 3 (Infantería), 4 (Infantería), 5 (Puesto avanzado), 6 (Base), 7 (Centinela)

## partido de liga
### 1(Héroe), 3(Infantería), 4(Infantería), 6(Base), 7(Centinela)
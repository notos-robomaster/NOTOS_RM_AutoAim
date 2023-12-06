# NOTOS_RM_AutoAim
#### Ce projet est le code complet pour la fonction de vision de la saison 2024 de l'équipe Nanfeng de l'Université de technologie du Sud de la Chine.

---
[![切换中文](https://img.shields.io/badge/切换语言-中文-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.zh.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README.md)
[![言語切り替え-日本語-blue](https://img.shields.io/badge/言語切り替え-日本語-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.jp.md)
[![Changer la langue-Français-blue](https://img.shields.io/badge/Changer%20la%20langue-Fran%C3%A7ais-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.fr.md)
[![Cambiar Idioma-Español-blue](https://img.shields.io/badge/Cambiar%20Idioma-Espa%C3%B1ol-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.es.md)
[![تغيير اللغة-العربية-blue](https://img.shields.io/badge/تغيير%20اللغة-العربية-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ar.md)
[![Изменить язык-Русский-blue](https://img.shields.io/badge/Изменить%20язык-Русский-blue)](https://github.com/lizuju/NOTOS_RM_AutoAim/blob/main/README/README.ru.md)
---

# Description du Répertoire

## Répertoire du Projet
    .
    ├── AngleSolver                 // Bibliothèque de résolution d'angle, comprenant la classe AngleSolver
    │   ├── AngleSolver.cpp         // 
    │   ├── AngleSolver.h           // 
    ├── Armor                       // Bibliothèque de reconnaissance d'armure, comprenant la classe Armor
    │   ├── Armor.h                 // Fichier d'en-tête de reconnaissance d'armure
    │   ├── LightBar.cpp            // Fichier d'en-tête de reconnaissance de la barre lumineuse
    │   ├── ArmorBox.cpp）          // Fichier de paramètres d'armure
    │   ├── ArmorNumClassifier.cpp  // Fichier d'en-tête de reconnaissance des chiffres
    │   ├── findLights.cpp          // Fichier d'en-tête de reconnaissance de la barre lumineuse
    │   ├── matchArmors.cpp         // Fichier d'en-tête de correspondance des armures
    │   └── ArmorDetector.cpp       // Fichier initial de reconnaissance d'armure
    ├── Calibration                 // Bibliothèque d'auto-orientation, comprenant la classe AutoAim
    │   ├── Image                   // Dossier d'images
    │   ├── Calibaration.cpp        // Calibration de la caméra
    ├── cmake-build-debug           // Dossier généré par la compilation
    ├── General                     // 
    │   ├── 123svm.xml              // 
    │   ├── camera_params.xml     	// 
    │   ├── General.h               // 
    ├── MindVision                  // Fichiers de la caméra
    │   ├── head                    // Fichiers d'en-tête de la caméra
    │   │   ├── CameraApi.h         // 
    │   │   ├── CameraCapture.h     // 
    │   │   ├── CameraDefine.h      // 
    │   │   └── CameraStatus.h      // 
    │   └── cameramain.cpp          // Fonction principale de la caméra
    ├── Serial                      // Bibliothèque de communication série, comprenant la classe Serial
    │   ├── CRC_Check.cpp           // Vérification CRC
    │   ├── CRC_Check.h             // Fichier d'en-tête de vérification CRC
    │   ├── serialport.cpp          // Classe de communication série
    │   └── serailport.h            // Fichier d'en-tête de la classe de communication série
    ├── AutoAim.cpp                 // Classe d'auto-orientation
    ├── CMakeLists.txt              // Fichier de projet CMake
    ├── CodeStandard                //
    ├── Debug.h                     // Fichier d'en-tête de débogage
    ├── Imagelnit.cpp               // 
    ├── Main.cpp                    // Fonction principale
    ├── LICENSE                     // Licence 
    ├── main.cpp                    // Fonction principale
    ├── README.md                   // Fichier de description du projet
    └── WatchDog.sh                 // Script de débogage
# NOTOS_RM_AutoAim
#### Ce projet est le code complet de la fonction visuelle de l'équipe Nanfeng du Guangzhou Nanfeng College pour la saison 2024.

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

# Description de l'entrepôt

## Répertoire de l'entrepôt
    ├── AngleSolver                 // Bibliothèque de résolution d'angle, comprenant la classe de résolution d'angle
    │   ├── AngleSolver.cpp         // Fichier de résolution d'angle
    │   ├── AngleSolver.h           // Fichier d'en-tête de résolution d'angle
    ├── Armor                       // Bibliothèque de reconnaissance d'armure, comprenant la classe de reconnaissance d'armure
    │   ├── Armor.h                 // Fichier d'en-tête de reconnaissance d'armure
    │   ├── LightBar.cpp            // Fichier de paramètres de barre lumineuse
    │   ├── ArmorBox.cpp            // Fichier de paramètres d'armure
    │   ├── ArmorNumClassifier.cpp  // Fichier de reconnaissance de chiffres
    │   ├── findLights.cpp          // Fichier de reconnaissance de barres lumineuses
    │   ├── matchArmors.cpp         // Fichier d'appariement d'armures
    │   └── ArmorDetector.cpp       // Fichier initial de reconnaissance d'armure
    ├── Calibration                 // Fichier d'étalonnage de la caméra
    │   ├── Image                   // Dossier de données d'image
    │   ├── Calibaration.cpp        // Étalonnage de la caméra
    │   ├── file_images.txt         // Chemin des images
    ├── cmake-build-debug           // Dossier de données généré par la compilation
    ├── General                     // Fichier de configuration
    │   ├── 123svm.xml              // Classificateur de chiffres
    │   ├── camera_params.xml     	// Fichier de configuration de la caméra
    │   ├── General.h               // Fichier d'en-tête général
    ├── MindVision                  // Fichier d'archive de la caméra
    │   ├── head                    // Fichier d'en-tête de la caméra
    │   │   ├── CameraApi.h         // Fichier API de la caméra
    │   │   ├── CameraCapture.h     // Fichier d'interface de la caméra
    │   │   ├── CameraDefine.h      // Fichier de paramètres de la caméra
    │   │   └── CameraStatus.h      // Fichier de définition de la caméra
    │   └── cameramain.cpp          // Fonction principale de la caméra
    ├── README                      // Fichier d'instructions
    │   ├── README.de.md            // Fichier d'instructions en allemand
    │   ├── README.es.md            // Fichier d'instructions en espagnol
    │   ├── README.fr.md            // Fichier d'instructions en français
    │   ├── README.jp.md            // Fichier d'instructions en japonais
    │   ├── README.ru.md            // Fichier d'instructions en russe
    │   ├── README.zh-cn.md         // Fichier d'instructions en chinois simplifié
    │   └── README.zh-tc.md         // Fichier d'instructions en chinois traditionnel
    ├── Serial                      // Bibliothèque de communication série, comprenant la classe de communication série
    │   ├── CRC_Check.cpp           // Vérification CRC
    │   ├── CRC_Check.h             // Fichier d'en-tête de vérification CRC
    │   ├── serialport.cpp          // Classe de communication série
    │   └── serailport.h            // Fichier d'en-tête de la classe de communication série
    ├── AutoAim.cpp                 // Classe de visée automatique
    ├── CMakeLists.txt              // Fichier de projet CMake
    ├── Debug.h                     // Fichier d'en-tête de débogage
    ├── Imagelnit.cpp               // Fichier d'initialisation de l'image
    ├── LICENSE                     // Licence
    ├── main.cpp                    // Fonction principale
    ├── README.md                   // Fichier d'instructions en anglais
    └── WatchDog.sh                 // Script de démarrage automatique


# Description des armes

## Super concours
### 1 (Héros), 2 (Ingénieur), 3 (infanterie), 4 (infanterie), 5 (avant-poste), 6 (base), 7 (sentinelle)

## Match de championnat
### 1 (Héros), 3 (Infanterie), 4 (Infanterie), 6 (Base), 7 (Sentinelle)
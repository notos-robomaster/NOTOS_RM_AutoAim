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
---

# Description de l'entrepôt

## Répertoire de l'entrepôt
     .
     ├── AngleSolver                // Bibliothèque de solveurs d'angle, y compris la classe de solveur d'angle
     │ ├── AngleSolver.cpp          // Fichier de solution d'angle
     │ ├── AngleSolver.h            // Fichier d'en-tête de solution d'angle
     ├── Armor                      // Bibliothèque de reconnaissance de plaques de blindage, y compris la classe de reconnaissance de plaques de blindage
     │ ├── Armor.h                  // Fichier d'en-tête d'identification de plaque de blindage
     │ ├── LightBar.cpp             // Fichier de paramètres de barre lumineuse
     │ ├── ArmorBox.cpp             // Fichier de paramètres de plaque de blindage
     │ ├── ArmorNumClassifier.cpp   // Fichier d'identification numérique
     │ ├── findLights.cpp           // Fichier d'identification de la barre lumineuse
     │ ├── matchArmors.cpp          // Fichier de correspondance de plaques de blindage
     │ └── ArmorDetector.cpp        // Fichier initial de reconnaissance des plaques de blindage
     ├── Calibration                // Fichier de calibrage de la caméra
     │ ├── Image                    // Dossier images
     │ ├── Calibaration.cpp         // Calibrage de la caméra
     │ ├── file_images.txt          // Chemin de l'image
     ├── cmake-build-debug          // Compiler et générer le dossier
     ├── General                    // Fichier de configuration
     │ ├── 123svm.xml               // Classificateur numérique
     │ ├── camera_params.xml        // Fichier de configuration de la caméra
     │ ├── General.h                // Fichier d'en-tête général
     ├── MindVision                 // Fichier caméra
     │ ├── head                     // fichier d'en-tête de la caméra
     │ │ ├── CameraApi.h            // Fichier API de caméra
     │ │ ├── CameraCapture.h        // Fichier d'interface de caméra
     │ │ ├── CameraDefine.h         // Fichier de paramètres de caméra
     │ │ └── CameraStatus.h         // Fichier de définition de caméra
     │ └── cameramain.cpp           // Fonction principale de la caméra
     ├── Serial                     // Bibliothèque de communication série, y compris la classe de communication série
     │ ├── CRC_Check.cpp            // Vérification CRC
     │ ├── CRC_Check.h              // Fichier d'en-tête de vérification CRC
     │ ├── serialport.cpp           // Classe de communication série
     │ └── serailport.h             // Fichier d'en-tête de catégorie de communication série
     ├── AutoAim.cpp                // Classe de visée automatique
     ├── CMakeLists.txt             // Fichier de projet CMake
     ├── Debug.h                    // Fichier d'en-tête de débogage
     ├── Imagelnit.cpp              // Fichier d'initialisation de l'image
     ├── LICENCE                    // Licence
     ├── main.cpp                   // fonction principale
     ├── README.md                  // Fichier de description du projet
     └── WatchDog.sh                // Script à démarrage automatique

# Description des armes

## Super concours
### 1 (Héros), 2 (Ingénieur), 3 (infanterie), 4 (infanterie), 5 (avant-poste), 6 (base), 7 (sentinelle)

## Match de championnat
### 1 (Héros), 3 (Infanterie), 4 (Infanterie), 6 (Base), 7 (Sentinelle)
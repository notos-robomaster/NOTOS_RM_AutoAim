# NOTOS_RM_AutoAim
#### Dieses Projekt ist der vollständige Code für die Saison 2024 des Southern Wind-Teams der South China Normal University.

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

# Repository-Beschreibung

## Verzeichnis des Repositorys
    ├── AngleSolver                 // Bibliothek für Winkellösung mit einer Klasse für die Winkellösung
    │   ├── AngleSolver.cpp         // Datei für die Winkellösung
    │   ├── AngleSolver.h           // Header-Datei für die Winkellösung
    ├── Armor                       // Bibliothek für die Erkennung von Rüstungen mit einer Klasse für die Rüstungserkennung
    │   ├── Armor.h                 // Header-Datei für die Rüstungserkennung
    │   ├── LightBar.cpp            // Datei mit den Parametern für Lichtleisten
    │   ├── ArmorBox.cpp            // Datei mit den Parametern für Rüstungen
    │   ├── ArmorNumClassifier.cpp  // Datei für die Ziffernerkennung
    │   ├── findLights.cpp          // Datei für die Erkennung von Lichtleisten
    │   ├── matchArmors.cpp         // Datei für das Abgleichen von Rüstungen
    │   └── ArmorDetector.cpp       // Startdatei für die Rüstungserkennung
    ├── Calibration                 // Datei für die Kamerakalibrierung
    │   ├── Image                   // Ordner mit Bilddaten
    │   ├── Calibaration.cpp        // Kamerakalibrierung
    │   ├── file_images.txt         // Bildpfade
    ├── cmake-build-debug           // Ordner mit kompilierten Daten
    ├── General                     // Konfigurationsdateien
    │   ├── 123svm.xml              // Ziffernklassifikator
    │   ├── camera_params.xml     	// Datei für die Kamerakonfiguration
    │   ├── General.h               // Allgemeine Header-Datei
    ├── MindVision                  // Dateien für die Kamerakonfiguration
    │   ├── head                    // Header-Dateien für die Kamera
    │   │   ├── CameraApi.h         // Datei für die Kamera-API
    │   │   ├── CameraCapture.h     // Datei für die Kamera-Schnittstelle
    │   │   ├── CameraDefine.h      // Datei für die Kameraparameter
    │   │   └── CameraStatus.h      // Datei für die Kameradefinitionen
    │   └── cameramain.cpp          // Hauptdatei für die Kamera
    ├── README                      // Datei für die Beschreibung
    │   ├── README.de.md            // Datei für die deutsche Beschreibung
    │   ├── README.es.md            // Datei für die spanische Beschreibung
    │   ├── README.fr.md            // Datei für die französische Beschreibung
    │   ├── README.jp.md            // Datei für die japanische Beschreibung
    │   ├── README.ru.md            // Datei für die russische Beschreibung
    │   ├── README.zh-cn.md         // Datei für die chinesische (vereinfachte) Beschreibung
    │   └── README.zh-tc.md         // Datei für die chinesische (traditionelle) Beschreibung
    ├── Serial                      // Bibliothek für die serielle Kommunikation mit einer Klasse für die serielle Kommunikation
    │   ├── CRC_Check.cpp           // CRC-Prüfung
    │   ├── CRC_Check.h             // Header-Datei für die CRC-Prüfung
    │   ├── serialport.cpp          // Klasse für die serielle Kommunikation
    │   └── serailport.h            // Header-Datei für die Klasse für die serielle Kommunikation
    ├── AutoAim.cpp                 // Klasse für die automatische Zielrichtung
    ├── CMakeLists.txt              // CMake-Projektdatei
    ├── Debug.h                     // Header-Datei für die Fehlerbehebung
    ├── Imagelnit.cpp               // Datei für die Initialisierung von Bildern
    ├── LICENSE                     // Lizenz
    ├── main.cpp                    // Hauptfunktion
    ├── README.md                   // Datei für die englische Beschreibung
    └── WatchDog.sh                 // Skript für den automatischen Start

# Einheitenbeschreibung

## Super Combat Game
### 1 (Held), 2 (Ingenieur), 3 (Infanterie), 4 (Infanterie), 5 (Vorpostenkampf), 6 (Basis), 7 (Wachposten)

## League Game
### 1 (Held), 3 (Infanterie), 4 (Infanterie), 6 (Basis), 7 (Wachposten)
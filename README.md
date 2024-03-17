# NOTOS_RM_AutoAim
This project is the complete code for the visual function of the Guangzhou Nanfeng College Notos Team in the 2024 season.

---
[![切换简体中文](https://img.shields.io/badge/切换语言-简体中文-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README/README.zh-cn.md)
[![切換繁體中文](https://img.shields.io/badge/切換語言-繁體中文-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README/README.zh-tc.md)
[![Switch to English](https://img.shields.io/badge/Switch-English-blue)](https://github.com/notos-robomaster/NOTOS_RM_AutoAim/blob/main/README.md)
---

## Repository description
Repository directory

     .
     ├── AngleSolver                // angle solver library, including angle solver class
     │ ├── AngleSolver.cpp          // angle solution file
     │ └─── AngleSolver.h           // angle solution header file
     ├── Armor                      // armor plate recognition library, including armor plate recognition class
     │ ├── Armor.h                  // armor plate identification header file
     │ ├── LightBar.cpp             // light bar parameter file
     │ ├── ArmorBox.cpp             // armor plate parameter file
     │ ├── ArmorNumClassifier.cpp   // digital identification file
     │ ├── findLights.cpp           // light bar identification file
     │ ├── matchArmors.cpp          // armor plate matching file
     │ └── ArmorDetector.cpp        // armor plate recognition initial file
     ├── Calibration                // camera calibration file
     │ ├── Image                    // image folder
     │ ├── Calibaration.cpp         // camera calibration
     │ └── file_images.txt          // image path
     ├── cmake-build-debug          // compile and generate folder
     ├── General                    // configuration file
     │ ├── 123svm.xml               // digital classifier
     │ ├── camera_params.xml        // camera configuration file
     │ └── General.h                // general header file
     ├── GraphWindow                // Graph window
     │ ├── MotionDetection.cpp      // Motion detection file
     │ ├── MotionDetection.h        // Motion detection header file
     │ ├── qcustomplot.cpp          // qt plot configuration file
     │ └── qcustomplot.h            // qt plot configuration header file
     ├── Filter                     // filter solve
     │ ├── Kalman.cpp               // kalman solve file
     │ └── Kalman.cpp               // kalman solve header file
     ├── MindVision                 // camera File
     │ ├── head                     // camera header file
     │ │ ├── CameraApi.h            // camera API file
     │ │ ├── CameraCapture.h        // camera interface file
     │ │ ├── CameraDefine.h         // camera parameter file
     │ │ └── CameraStatus.h         // camera definition file
     │ └── cameramain.cpp           // camera main function
     ├── README                     // README file
     │ ├── README.zh-cn.md          // Simplified Chinese description file
     │ └── README.zh-tc.md          // Traditional Chinese description file
     ├── Serial                     // serial communication library, including serial communication class
     │ ├── CRC_Check.cpp            // CRC check
     │ ├── CRC_Check.h              // CRC check header file
     │ ├── serialport.cpp           // serial communication class
     │ └── serailport.h             // serial communication category header file
     ├── AutoAim.cpp                // automatic aiming class
     ├── CMakeLists.txt             // cMake project file
     ├── Debug.h                    // debug header file
     ├── Imagelnit.cpp              // image initialization file
     ├── LICENSE                    // License
     ├── main.cpp                   // main function
     ├── README.md                  // project description file
     └── WatchDog.sh                // self-starting script

## Communication protocol with stm32
Mini PC sent:

| Byte0 | Byte1 | Byte2          | Byte3        | Byte4            | Byte5          | Byte6     | Byte7 |
|-------|-------------|----------------|--------------|------------------|----------------|-----------|-------|
| 0x16  | IsHaveArmor | YawAngleSymbol | YawAngleData | PitchAngleSymbol | PitchAngleData | CRC_Check | 0xFE  |

Mini PC receive:

| Byte0        | Byte1          | Byte2      | Byte3   |
|--------------|----------------|------------|---------|
| IsHaveKalman | ArmorSelection | ArmorColor | 0x03 |

## Graph window
Motion detection handle click events

| MouseLeftButton  | MouseMiddleButton | MouseRightButton |
|------------------|-------------------|------------------|
| CalibrationPoint | ContinuePlot      | InterruptPlot    |

## Description of arms

### Super contest
1(Hero), 2(Engineer), 3(Infantry), 4(Infantry), 5(Outpost), 6(Base), 7(Sentinel)

### League match
1(Hero), 3(Infantry), 4(Infantry), 6(Base), 7(Sentinel)

## v2ray self-starting script
$sudo systemctl start v2raya.service

## open the serialPort script
$sudo chmod 777 /dev/ttyUSB0
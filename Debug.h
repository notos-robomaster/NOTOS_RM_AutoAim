//===========================================================================//
//                          FIXME: debug options
// open v2ray $ sudo systemctl start v2raya.service
// open serialPort $ sudo chmod 777 /dev/ttyUSB0
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
#define ALL_DEBUG_MOOD  // show all file
#define DETECT_DEBUG_MOOD   // show armor file
#define SOLVER_DEBUG_MOOD   // show solver file
#define PREDICT_DEBUG_MOOD  // show predict file
//===========================================================================//



//===========================================================================//
//                          Hardware device options
// TODO: Make sure define comment state are reasonable
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
#define USING_MINDVISION    // using MindVision
//#define USING_USB_CAMERA    // using usb camera
//#define VIDEO_PATH "/home/cgnb/TheNewBegging/testArmor.mp4"    // using video

#define WAIT_RECEIVE  // wait serial port to receive data
//===========================================================================//



//===========================================================================//
//                            Image debug options
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//
//#define SHOW_SRCIMG // show src
//#define SHOW_SRCBINARY  // show binary
//#define SHOW_LIGHTS // show light
#define SHOW_ARMORS // show armors
//#define SHOW_ARMORNUM   // show armor number
//#define TEXT_LIGHTS // light info
//#define TEXT_ARMORS // armors info
//#define TEXT_SCORES // impact info

#define SHOW_ANGLE // show angle result
//#define TEXT_TVEC   // tVec info
//#define TEXT_P4P // P4P solver info
//#define TEXT_PINHOLE    // PinHole solver info
//#define TEXT_COMPENSATION   // compensation info
//#define TEXT_CAMERA_PARAMS  // camera params info

//#define SHOW_PREDICT    // show predict info

#define TEXT_FPS    // fps info

//#define SHOW_PLOT // show motion detection in plot

#define TEXT_ISRECEIVE  // whether to receive serial port
//===========================================================================//
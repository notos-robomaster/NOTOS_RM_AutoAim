#include "Armor/Armor.h"
#include "General/General.h"
#include "AngleSolver/AngleSolver.h"
#include "Serial/serialport.h"
#include "Filter/Kalman.h"
#include "GraphWindow/MotionDetection.h"

ArmorDetector detector;
AngleSolver angleSolver;
Kalman kalman;
#ifdef SHOW_PLOT
int argc;
char **argv = nullptr;
QApplication a(argc, argv);
MotionDetect motionDetect;
#endif // SHOW_PLOT

//Color ENEMYCOLOR = BLUE;
Color ENEMYCOLOR = RED;

int targetNum = 3;
unsigned char readData[3];

bool bRun = true;
bool firstTime = true;

char ttyUSB_path[] = "/dev/ttyUSB0";    //设置串口名称
SerialPort port(ttyUSB_path);   //创建串口类对象

void autoaimRun()
{
    detector.loadSVM("../General/123svm.xml");  // todo SVM update

    angleSolver.setCameraParam("../General/camera_params.xml", 2);
    angleSolver.setArmorSize(SMALL_ARMOR, 135, 125);
    angleSolver.setArmorSize(BIG_ARMOR, 230, 127);
    angleSolver.setBulletSpeed(15000);

    port.initSerialPort();  //串口初始化

    imageInit();

    do
    {
        fpsInit();

        // Serial
#ifdef WAIT_RECEIVE
        port.receive(readData);
//        for (int i = 0; i < sizeof(readData)/sizeof(readData[0]); i++)
//        {
//            cout << (int)readData[i] << endl;
//        }

        // Wait for the referee system to read the color
        if (firstTime)
        {
            if (readData[3] == 0x03)
            {
                firstTime = false;
                // if data is 0, mean our COLOR is RED; enemy COLOR is BLUE
                if (readData[2] == 0)   ENEMYCOLOR = BLUE;
                if (readData[2] == 1)   ENEMYCOLOR = RED;
            }
        }
#endif // WAIT_RECEIVE

        detector.setEnemyColor(ENEMYCOLOR);
        imageUpdating();
        detector.setImg(src);
        detector.run(src);

        double yaw = 0, pitch = 0, distance = 0;
        Point2f centerPoint;
        if (detector.isFoundArmor())
        {
            vector<Point2f> contourPoints;
            ArmorType type;
            detector.getTargetInfo(contourPoints, centerPoint, type);
            centerPoint = kalman.predictRun(centerPoint);
            angleSolver.getAngle(contourPoints, centerPoint, SMALL_ARMOR, yaw, pitch, distance);
        }

        // Serial
        port.TransformData_Part(detector.isFoundArmor(), yaw, pitch);
        port.send();

#ifdef WAIT_RECEIVE
        if (readData[3] == 3)
        {
            if (readData[1] == 1)       targetNum = 1;
            else if (readData[1] == 2)  targetNum = 2;
            else if (readData[1] == 3)  targetNum = 3;
            else if (readData[1] == 4)  targetNum = 4;
            else if (readData[1] == 5)  targetNum = 5;
            else if (readData[1] == 6)  targetNum = 6;
        }
#endif // WAIT_RECEIVE

        detector.setTargetNum(targetNum);

        fpsUpdating();

#ifdef ALL_DEBUG_MOOD
#ifdef SHOW_PLOT
        motionDetect.setPoint(yaw, 0);
        motionDetect.setPoint(pitch, 1);
#endif // SHOW_PLOT
        detector.showDebugInfo();
        if (detector.isFoundArmor())
        {
            angleSolver.showDebugInfo();
            kalman.showDebugInfo(src);
        }
#endif // ALL_DEBUG_MOOD

        char chKey = waitKey(1);
        switch (chKey)
        {
            case '0':
                targetNum = 0;
            case '1':
                targetNum = 1;
                break;
            case '2':
                targetNum = 2;
                break;
            case '3':
                targetNum = 3;
                break;
            case 'i':
            case 'I':
                targetNum = 4;
                break;
            case 'b':
            case 'B':
                ENEMYCOLOR = BLUE;
                break;
            case 'r':
            case 'R':
                ENEMYCOLOR = RED;
                break;
            case 'q':
            case 'Q':
            case 27:
                bRun = false;
                break;
            default:
                break;
        }
    } while (bRun);
}

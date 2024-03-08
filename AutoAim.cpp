#include "Armor/Armor.h"
#include "General/General.h"
#include "AngleSolver/AngleSolver.h"
#include "Serial/serialport.cpp"
#include "Filter/Kalman.h"

ArmorDetector detector;
AngleSolver angleSolver;
Kalman kalman;

int targetNum = 3;
//Color ENEMYCOLOR = BLUE;
Color ENEMYCOLOR = RED;

bool bRun = true;

void autoaimRun()
{
    detector.loadSVM("../General/123svm.xml");  // todo SVM update

    angleSolver.setCameraParam("../General/camera_params.xml", 2);
    angleSolver.setArmorSize(SMALL_ARMOR, 135, 125);
    angleSolver.setArmorSize(BIG_ARMOR, 230, 127);
    angleSolver.setBulletSpeed(15000);

    char ttyUSB_path[] = "/dev/ttyUSB0";    //设置串口名称
    SerialPort port(ttyUSB_path);   //创建串口类对象
    port.initSerialPort();  //串口初始化

    imageInit();

    do
    {
        fpsInit();

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
        cout << port.receive();

        detector.setTargetNum(targetNum);

        fpsUpdating();

#ifdef ALL_DEBUG_MOOD
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

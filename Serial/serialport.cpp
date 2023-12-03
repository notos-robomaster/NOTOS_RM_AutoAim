#include "serialport.h"
//int Data_1=2,Data_2=2,Data_3=3,Data_4=4,Data_5=5,Data_6=6,Data_7=7;
//int part = 1;

int length = 10;
//int *ptr = &part;
int *len = &length;

/**
 *@brief   初始化数据
 *@param  fd       类型  int  打开的串口文件句柄
 *@param  speed    类型  int  波特率
 *@param  databits 类型  int  数据位   取值 为 7 或者8
 *@param  stopbits 类型  int  停止位   取值为 1 或者2
double
 *@param  portchar 类型  char* 串口路径
 */

SerialPort::SerialPort() // 打开默认
{
    fd = open(UART_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    speed = BAUDRATE;
    databits = 8;
    stopbits = 1;
    parity = 'N';
}

SerialPort::SerialPort(char *portpath) // 自定义打开设备
{
    fd = open(portpath, O_RDWR | O_NOCTTY | O_NDELAY);
    speed = BAUDRATE;
    databits = 8;
    stopbits = 1;
    parity = 'N';
}

/**
 *@brief   初始化串口
 */
bool SerialPort::initSerialPort()
{
    if (fd == -1)
    {
        perror(UART_DEVICE);
        return false;
    }

    std::cout << "Opening..." << std::endl;
    set_Brate();

    if (set_Bit() == FALSE)
    {
        printf("Set Parity Error\n");
        exit(0);
    }
    printf("Open successed\n");
    return true;
}

/**
 *@brief   设置波特率
 */
void SerialPort::set_Brate()
{
    int speed_arr[] = {
        B115200,
        B38400,
        B19200,
        B9600,
        B4800,
        B2400,
        B1200,
        B300,
        B115200,
        B38400,
        B19200,
        B9600,
        B4800,
        B2400,
        B1200,
        B300,
    };
    int name_arr[] = {
        115200,
        38400,
        19200,
        9600,
        4800,
        2400,
        1200,
        300,
        115200,
        38400,
        19200,
        9600,
        4800,
        2400,
        1200,
        300,
    };
    int i;
    int status;
    struct termios Opt;
    tcgetattr(fd, &Opt);

    for (i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
    {
        if (speed == name_arr[i])
        {
            tcflush(fd, TCIOFLUSH);          // 清空缓冲区的内容
            cfsetispeed(&Opt, speed_arr[i]); // 设置接受和发送的波特率
            cfsetospeed(&Opt, speed_arr[i]);
            status = tcsetattr(fd, TCSANOW, &Opt); // 使设置立即生效

            if (status != 0)
            {
                perror("tcsetattr fd1");
                return;
            }

            tcflush(fd, TCIOFLUSH);
        }
    }
}

/**
 *@brief   设置串口数据位，停止位和效验位
 */
int SerialPort::set_Bit()
{
    struct termios termios_p;

    if (tcgetattr(fd, &termios_p) != 0)
    {
        perror("SetupSerial 1");
        return (FALSE);
    }

    termios_p.c_cflag |= (CLOCAL | CREAD); // 接受数据
    termios_p.c_cflag &= ~CSIZE;           // 设置数据位数

    switch (databits)
    {
    case 7:
        termios_p.c_cflag |= CS7;
        break;

    case 8:
        termios_p.c_cflag |= CS8;
        break;

    default:
        fprintf(stderr, "Unsupported data size\n");
        return (FALSE);
    }

    // 设置奇偶校验位double
    switch (parity)
    {
    case 'n':
    case 'N':
        termios_p.c_cflag &= ~PARENB; /* 清除 PARENB 标志位 */
        termios_p.c_iflag &= ~INPCK;  /* 启用校验位检查 INPCK */
        break;

    case 'o':
    case 'O':
        termios_p.c_cflag |= (PARODD | PARENB); /* 设置为奇效验*/
        termios_p.c_iflag |= INPCK;             /* 设置 PARODD 和 PARENB 标志位，禁用校验位检查 INPCK。 */
        break;

    case 'e':
    case 'E':
        termios_p.c_cflag |= PARENB;  /* Enable parity */
        termios_p.c_cflag &= ~PARODD; /* 转换为偶效验*/
        termios_p.c_iflag |= INPCK;   /* Disnable parity checking */
        break;

    case 'S':
    case 's': /*as no parity*/
        termios_p.c_cflag &= ~PARENB;
        termios_p.c_cflag &= ~CSTOPB;
        break;

    default:
        fprintf(stderr, "Unsupported parity\n");
        return (FALSE);
    }

    /* 设置停止位*/
    switch (stopbits)
    {
    case 1:
        termios_p.c_cflag &= ~CSTOPB;
        break;

    case 2:
        termios_p.c_cflag |= CSTOPB;
        break;

    default:
        fprintf(stderr, "Unsupported stop bits\n");
        return (FALSE);
    }

    /* Set input parity option */
    if (parity != 'n') /*如果不为无校验则启用奇校验*/
        termios_p.c_iflag |= INPCK;

    tcflush(fd, TCIFLUSH);                                // 清除输入缓存区
    termios_p.c_cc[VTIME] = 150;                          /* 设置超时15秒*/
    termios_p.c_cc[VMIN] = 0;                             // 最小接收字符
    termios_p.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); /*Input原始输入*/
    termios_p.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    termios_p.c_iflag &= ~(ICRNL | IGNCR);
    termios_p.c_oflag &= ~OPOST; /*Output禁用输出处理*/

    if (tcsetattr(fd, TCSANOW, &termios_p) != 0) /* 配置串口属性，并返回错误信息 */
    {
        perror("SetupSerial 3");
        return (FALSE);
    }
    return (TRUE);
}

void SerialPort::send()
{
    write(fd, Tdata, length);
}

void SerialPort::TransformData_Global(int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6)//打包 全局
{
    Tdata[0] = 0x13;
    Tdata[1] = 0x01;
    Tdata[2] = Data_1;
    Tdata[3] = Data_2;
    Tdata[4] = Data_3;
    Tdata[5] = Data_4;
    Tdata[6] = Data_5;
    Tdata[7] = Data_6;
    Append_CRC8_Check_Sum(Tdata,9);
    Tdata[9] = 0xFE;
    *len = 10;
}

void SerialPort::TransformData_Part(int Data_1, int Data_2, bool part)//打包 局部
{
    Tdata[0] = 0x13;
    Tdata[1] = part;
    Tdata[2] = Data_1;
    Tdata[3] = Data_2;
    Append_CRC8_Check_Sum(Tdata,5);
    Tdata[5] = 0xFE;
    *len = 6;
}

// 关闭通讯协议接口
void SerialPort::closePort()
{
    close(fd);
}
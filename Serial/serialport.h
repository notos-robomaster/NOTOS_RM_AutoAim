#pragma once
#ifndef SERIALPORT_H
#define SERIALPORT_H
/**
 *@class  SerialPort
 *@brief  set serialport,recieve and send
 *@param  int fd
 */
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <iostream>
#include "CRC_Check.cpp"
using namespace std;
using ReceiveCallback = function<void (char*, int)>;

#define TRUE 1
#define FALSE 0

//串口的相关参数
#define BAUDRATE 115200//波特率
#define UART_DEVICE "/dev/ttyUSB0"//默认的串口名称

//C_lflag
#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)

class SerialPort
{
private:
    int fd; //串口号
    int speed, databits, stopbits, parity;
    unsigned char rdata[255]; //原数据
    unsigned char Tdata[30];  //处理后数据
    unsigned char Rdata[1];
	void set_Brate();
	int set_Bit();
public:
    SerialPort();
    SerialPort(char *);
    bool initSerialPort();//串口初始化
	void TransformData_Part(bool part, int Data_1, int Data_2);
    void TransformData_Global(int Data_1, int Data_2, int Data_3, int Data_4, int Data_5, int Data_6);
	void send();//piuuuu～
    bool receive();//ahhhhh～
	void closePort();//关串口
};

#endif //SERIALPORT_H


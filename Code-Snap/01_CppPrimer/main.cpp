//
// Created by xuqi on 2019-05-06.
//
#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstdlib>
#include<time.h>

#include <sys/timeb.h>

#include "ThreadManager.h"
#include "StdTask.h"

using namespace std;

typedef unsigned short u16;


#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>
#define MY_DEBUG(tag,fmt, args...) do { \
if (strcmp(tag,"phone") == 0) {   \
    printf("%s |" tag"|(%s:%d)\t" fmt "\n", log_Time(), __func__,__LINE__,##args);    \
}   \
if (strcmp(tag,"navi") == 0) {   \
    printf("%s |" tag"|(%s:%d)\t" fmt "\n", log_Time(), __func__,__LINE__,##args);    \
}   \
if (strcmp(tag,"media") == 0) {   \
    printf("%s |" tag"|(%s:%d)\t" fmt "\n", log_Time(), __func__,__LINE__,##args);    \
}   \
}while(0)



char * timeString() {
    struct timespec ts;
    clock_gettime( CLOCK_REALTIME, &ts);
    struct tm * timeinfo = localtime(&ts.tv_sec);
    static char timeStr[20];
    sprintf(timeStr, "%.2d:%.2d:%.2d.%.3ld", timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, ts.tv_nsec / 1000000);
    return timeStr;
}


void output(int i)
{
    cout << "int:" << i <<endl;
}

void output(float i)
{
    cout << "float:" << i << endl;
}

class Base
{
public:
    virtual void e(int i) {cout << "Base e\n";}
    virtual void f(int i,int j) {cout << "Base f2\n";}
    virtual void f(int i) {cout << "Base f1\n";}
};

class Device:public Base
{
public:
    virtual void e(int i) {cout << "Device e\n";}
    void f(int i,int j = 0) {cout << "Device f\n";}
};

bool IsBigEndian()
{
    int a = 0x1234;
    char b =  *(char *)&a;  //通过将int强制类型转换成char单字节，通过判断起始存储位置。即等于 取b等于a的低地址部分
    if( b == 0x12)
    {
        cout << "大端" <<endl;
        return true;
    }
    cout <<"小端"<<endl;
    return false;
}



char* log_Time(void)
{
    struct tm *ptm;
    struct timeb stTimeb;
    static char szTime[13];

    ftime(&stTimeb);
    ptm = localtime(&stTimeb.time);
    sprintf(szTime, "%02d:%02d:%02d.%03d",ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);
    szTime[13] = 0;
    return szTime;
}


void hello()
{
    while(1)
    {
        cout << "============>" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

}


int main()
{
    //output(1.0);
    Device d;
    Base *pb = &d;
    Device * pd = &d;

    pb->f(1); // Base f1
    pd->f(1); // Device f

    pb->e(1); // Device e
    pd->e(1); // Device e

    IsBigEndian();
    // 大小端
    char ary[4];
    printf("地址 低->高:%0x %0x %0x %0x\n",&ary[0],&ary[1], &ary[2], &ary[3]);
    int i = 0x01020304;
    //ary = (char*)(&i);
    ary[0] = 0x01;
    ary[1] = 0x02;
    ary[2] = 0x03;
    ary[3] = 0x04;

    printf("int是低位放低地址数据%0x\n",*(int*)(ary));
    MY_DEBUG("phone","test = %d\n",1);



    time_t unix_timestamp;
    time(&unix_timestamp);
    printf("unix_timestamp 现在的时间戳是=%d\n", unix_timestamp);

    printf("%s",log_Time());

    Task* task = new StdTask("aaa");

    task->create(hello);
    task->start();

//    cout << "\n======================" << endl;
//    ThreadManager::Inst()->runCase1();
//    cout << "======================" << endl;
//    ThreadManager::Inst()->runCase2();


    return 0;

}

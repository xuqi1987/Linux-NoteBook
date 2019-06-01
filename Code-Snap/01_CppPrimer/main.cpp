//
// Created by xuqi on 2019-05-06.
//
#include <iostream>
#include <bitset>
using namespace std;

typedef unsigned short u16;

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
    return 0;

}

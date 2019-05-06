//
// Created by xuqi on 2019-05-06.
//
#include <iostream>
#include <bitset>
using namespace std;

typedef unsigned short u16;

int main()
{
    u16 a = 1;
    u16 b = -65536;
    cout << b;
    bitset<32> bit32(0xabcdffff);
    cout << bit32;
}

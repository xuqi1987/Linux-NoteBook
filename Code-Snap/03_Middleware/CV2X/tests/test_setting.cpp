//
// Created by xuqi on 2019-07-30.
//
#include "v2xApp/V2xSettting.h"
#include <iostream>

using namespace std;
using namespace toolkit;
using namespace v2x;
int main()
{
    V2xSettting conf;

    conf["Debug.LOG"] = "ON";
    conf["Common.SpeedLimt"] = 60;
    conf.save();


    V2xSettting conf2;
    conf.load();
//    SET.load();
//
//    cout << SET["RV.TIME"];

    return 0;
}
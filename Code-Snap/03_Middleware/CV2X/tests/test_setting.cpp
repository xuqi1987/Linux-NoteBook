//
// Created by xuqi on 2019-07-30.
//
#include "v2xApp/V2xSetting.h"
#include <iostream>

using namespace std;
using namespace toolkit;
using namespace v2x;
int main()
{
    SET["Debug.LOG"] = "ON";


    SET.save();

    SET.load();

    cout << SET["Debug.LOG"];
//    SET.load();
//
//    cout << SET["RV.TIME"];

    return 0;
}
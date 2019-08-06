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

    SET.load();

    int loglevel = SET["Debug.MessageFrameLOG"].as<int>();
    bool replayswitch = SET["Debug.ScenceReplayFlag"].as<bool>();
    string path = SET["Debug.ReplayerFilePath"].as<string>();
    cout << "Log Level:"<<loglevel<<endl;
    cout << "replayswitch:"<<replayswitch<<endl;
    cout << "ReplayerFilePath:"<<path<<endl;
    return 0;
}
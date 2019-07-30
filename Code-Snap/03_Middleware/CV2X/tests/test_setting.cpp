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
    V2xSettting set1;
    set1["RV.a"] = 1 ;
    set1["RV.b"] = 2 ;
    set1["RV.c"] = 3;
    set1.dumpFile("./set.ini");

    V2xSettting set2;
    set2.parseFile("./set.ini");
    std::cout << set2["RV.c"];

    return 0;
}
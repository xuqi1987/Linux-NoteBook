/////////////////////////////////////////////////////////
//
// File:
//
// V2xAlgorithmAdapter.h
//
// Purpose
//
// <Describe here the purpose of the file>
// Ex:
// Definition of the String class
//
// File revision history:
//
// <comply with the configuration management system, or
// follow the following template:
// Date:
// Reason of change: create 1st version
// root
//
// Copyright Yanfeng Visteon Electronics Co.,Ltd
/////////////////////////////////////////////////////////

//
// Created by root on 19-8-23.
//

#ifndef CV2X_V2XALGORITHMADAPTER_H
#define CV2X_V2XALGORITHMADAPTER_H
#include "V2xAlgorithmTest.h"

namespace v2x {

#define Pos2Double(v) (v/100000.0) // deg
#define Heading2Double(v) (v*0.0125)  // deg
#define Speed2Double(v) (v * 0.02 * 3.6) // km/h

class V2xAlgorithmAdapter : public V2xAlgorithmTest
{
public:

    static double GetDistance(V2xBSMMsg &hv, V2xBSMMsg &rv);
    static Direction GetRVDirection(V2xBSMMsg &hv, V2xBSMMsg &rv);


};

}



#endif //CV2X_V2XALGORITHMADAPTER_H

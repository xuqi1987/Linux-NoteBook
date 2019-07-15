//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XCAR_H
#define CV2X_V2XCAR_H
#include <string>
#include "Util/Logger.h"

using namespace std;
using namespace toolkit;

namespace v2x {

class V2xMsgBSM : public string
{
public:
    typedef shared_ptr<V2xMsgBSM> Ptr;
    template<typename ...ArgTypes>
    V2xMsgBSM(ArgTypes &&...args) : string(std::forward<ArgTypes>(args)...){
        DebugL << "创建V2XCar对象:" << this << " " << *this;
    };

    ~V2xMsgBSM() {
        WarnL << "销毁string对象:" << this << " " << *this;
    }

// id
// E_DSecond 时间戳
// DF_Position3D
// DE_PositionConfidence  车辆经纬度
// DE_ElevationConfidence 车辆高度
// DE_TransmissionState 档位信息
// DE_Speed 车速
// DE_Heading 车头方向
// DF_AccelerationSet4Way 四轴加速度，横纵垂摆
// DF_BrakeSystemStatus 车身刹车系统 车轮，脚踏板，abs..
// DF_VehicleSize 车身大小

};

}


#endif //CV2X_V2XCAR_H

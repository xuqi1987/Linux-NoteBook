//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XCAR_H
#define CV2X_V2XCAR_H
#include <string>
#include "Util/Logger.h"
#include "V2xType.h"
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsgQueue.h"

using namespace std;
using namespace toolkit;

namespace v2x
{
/*
BasicSafetyMessage ::= SEQUENCE {
    msgCnt MsgCount,
    id OCTET STRING (SIZE(8)),
    -- vehicle ID
    plateNo OCTET STRING (SIZE(4..16)) OPTIONAL,
    -- Reserved for Electronic Vehicle Identification
    secMark DSecond,
    pos Position3D,
    accuracy PositionConfidenceSet,
    transmission TransmissionState,
    speed Speed,
    heading Heading,
    angle SteeringWheelAngle OPTIONAL,
    motionCfd MotionConfidenceSet OPTIONAL,
    accelSet AccelerationSet4Way,
    brakes BrakeSystemStatus,
    size VehicleSize,
    vehicleClass VehicleClassification,
    -- VehicleClassification includes BasicVehicleClass and other extendible type
    safetyExt VehicleSafetyExtensions OPTIONAL,
    ...
}
 */
/* BasicSafetyMessage */
typedef struct BasicSafetyMessage
{
    MsgCount_t msgCnt;
    uint32_t id;
    OCTET_STRING_t *plateNo    /* OPTIONAL */;
    DSecond_t secMark;
    Position3D_t pos;
    PositionConfidenceSet_t accuracy;
    TransmissionState_t transmission;
    Speed_t speed;
    Heading_t heading;
    SteeringWheelAngle_t *angle    /* OPTIONAL */;
    struct MotionConfidenceSet *motionCfd    /* OPTIONAL */;
    AccelerationSet4Way_t accelSet;
    BrakeSystemStatus_t brakes;
    VehicleSize_t size;
    VehicleClassification_t vehicleClass;
    struct VehicleSafetyExtensions *safetyExt    /* OPTIONAL */;
} V2xBSMMsg;

/*
MapData ::=	SEQUENCE {
    msgCnt MsgCount,
    timeStamp MinuteOfTheYear OPTIONAL,
    nodes NodeList,
    -- intersections or road endpoints
    ...
}
 */
/* MapData */
typedef struct MapData
{
    MsgCount_t msgCnt;
    MinuteOfTheYear_t *timeStamp    /* OPTIONAL */;
    NodeList_t nodes;

} V2xMapMsg;

/*
SPAT ::= SEQUENCE {
    msgCnt MsgCount,
    timeStamp MinuteOfTheYear OPTIONAL,
    name DescriptiveName OPTIONAL,
    -- human readable name for this collection
    -- to be used only in debug mode
    intersections IntersectionStateList,
    -- sets of SPAT data (one per intersection)
    ...
}

 */

/* SPAT */
typedef struct SPAT
{
    MsgCount_t msgCnt;
    MinuteOfTheYear_t *timeStamp    /* OPTIONAL */;
    DescriptiveName_t *name    /* OPTIONAL */;
    IntersectionStateList_t intersections;
} V2xSpatMsg;

class V2xMsg: public string
{
public:
    typedef shared_ptr<V2xMsg> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef V2xMsgQueue<ValuePtr> Queue;

    typedef enum
    {
        MSG_TYPE_HV_BSM = 0,
        MSG_TYPE_RV_BSM,
        MSG_TYPE_MAP,
        MSG_TYPE_SPAT,
        MSG_TYPE_MAX,
    } msg_type_e;

    union
    {
        V2xBSMMsg hvbsm; // HV BSM data
        V2xBSMMsg rvbsm; // RV BSM data
        V2xMapMsg mapintersecton;
        V2xSpatMsg spat;

    } u;

    template<typename ...ArgTypes>
    V2xMsg(ArgTypes &&...args)
        : string(std::forward<ArgTypes>(args)...)
    {
        TraceL << "创建V2xMsg对象:" << this << " " << *this;
    };

    ~V2xMsg()
    {
        DebugL << "销毁V2xMsg对象:" << this << " " << *this;
    };

    void Print();
    msg_type_e getMsgType() const;
    void setMsgType(msg_type_e msgType);

private:
    msg_type_e _msg_type;
};


}

#endif //CV2X_V2XCAR_H

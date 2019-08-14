//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XCAR_H
#define CV2X_V2XCAR_H
#include <string>
#include "Util/Logger.h"
#include "V2xType.h"
#include "Util/RecycleResourcePool.h"
#include "V2xMsgQueue.h"

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


/*
RoadSideInformation ::= SEQUENCE {
    msgCnt MsgCount,
    timeStamp MinuteOfTheYear OPTIONAL,
    id OCTET STRING (SIZE(8)),
    -- RSU ID
    rsiId INTEGER (0..255),
    -- local ID of this rsi information set by RSU
    alertType AlertType,
    -- Text message warning or Traffic sign type according to China GB5768
    description IA5String (SIZE(1..256)) OPTIONAL,
    -- Text message if alertType = 0
    -- Additional description to the traffic sign if alertType > 0
    -- e.g. describe the subtype of the traffic sign
    priority Priority OPTIONAL,
    -- the urgency of this message, a relative
    -- degree of merit compared with other
    -- similar messages for this type (not other
    -- messages being sent by the device), nor a
    -- priority of display urgency
    refPos Position3D,
    -- Position of traffic alert (traffic sign or incident)
    alertPath PathPointList,
    -- Warning is active if vehicle is within this path
    -- Points are listed from upstream to downstream
    -- along the vehicle drive direction.
    -- One path includes at least two points.
    alertRadius Radius,
    -- The biggest distance away from the alert path
    -- within which the warning is active.
    ...
}
 */


/* RoadSideInformation */
typedef struct RoadSideInformation
{
    MsgCount_t msgCnt;
    MinuteOfTheYear_t *timeStamp    /* OPTIONAL */;
    OCTET_STRING_t id;
    long rsiId;
    AlertType_t alertType;
    IA5String_t *description    /* OPTIONAL */;
    Priority_t *priority    /* OPTIONAL */;
    Position3D_t refPos;
    PathPointList_t alertPath;
    Radius_t alertRadius;
} V2xRsiMsg;

/*
RSM ::= SEQUENCE {
    msgCnt MsgCount,
    id OCTET STRING (SIZE(8)),
    -- RSU ID
    refPos Position3D,
    -- Reference position of this RSM message
    participants ParticipantList,//16byte
    -- All or part of the participants
    -- detected by RSU
    ...
}
 */

/* RoadsideSafetyMessage */
typedef struct RoadsideSafetyMessage
{
    MsgCount_t msgCnt;
    OCTET_STRING_t id;
    Position3D_t refPos;
    ParticipantList_t participants;
} V2xRsmMsg;

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


class V2xVechileStatus : public string
{
public:

    template<typename ...ArgTypes>
    V2xVechileStatus(ArgTypes &&...args)
    : string(std::forward<ArgTypes>(args)...)
    {
        TraceL << "创建V2xVechile对象:" << this << " " << *this;
    };

    ~V2xVechileStatus()
    {
        DebugL << "销毁V2xVechile对象:" << this << " " << *this;
    };

private:

    // 平均速度

    // 8方向距离最近的车


};
}

#endif //CV2X_V2XCAR_H

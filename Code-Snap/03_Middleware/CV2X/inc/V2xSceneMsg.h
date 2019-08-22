//
// Created by xuqi on 2019-07-23.
//

#ifndef V2XSCENE_H
#define V2XSCENE_H
#include <string>
#include "Util/Logger.h"
#include "V2xType.h"
#include "Util/ResourcePool.h"
#include "V2xMsgQueue.h"

using namespace std;
using namespace toolkit;

namespace v2x {


/* 道路危险状况提示 扩展数据 */
typedef struct HLWExt
{
    // 危险类型（具体多少种当前不确定
    typedef enum DangerType{

    }e_DangerType;
    e_DangerType dangerType;

} HLWExt_t;

/* 车内标牌提示 扩展数据 */
typedef struct IVSExt
{
    // enmu e_AlertType
    AlertType_t alertType;

} IVSExt_t;

/* 限速预警 扩展数据 */
typedef struct SLWExt
{
    // enmu e_RegulatorySpeedLimit
    RegulatorySpeedLimit_t regulatorySpeedLimit;

} SLWExt_t;

/* 闯红灯预警 扩展数据 */
typedef struct RLVWExt
{
    PhaseState_t phaseState;
} RLVWExt_t;

/* 绿波车速引导 扩展数据 */
typedef struct GLOSAExt
{

} GLOSAExt_t;

/* 前方道路拥堵提醒 扩展数据 */
typedef struct TJWExt
{

} TJWExt_t;


class V2xSceneMsg : public string
{
public:
    typedef shared_ptr<V2xSceneMsg> Ptr;
    typedef ResourcePool<V2xSceneMsg> Pool;
    typedef ResourcePool<V2xSceneMsg>::ValuePtr ValuePtr;
    typedef V2xMsgQueue<ValuePtr> Queue;

/*
//场景类型（一期场景十五种）
1	5.2.3	"交叉路口碰撞预警                         --Leve2            --
（ICW:Intersection Collision Warning）"	V2V/V2I
2	5.2.7	"紧急制动预警							  --Leve1
（EBW：Emergency Brake Warning）"	V2V
3	5.2.8	"异常车辆提醒							  --Leve1
（AVW: Abnormal Vehicle Warning）"	V2V
4	5.2.9	"车辆失控预警 							  --Leve1
（CLW：Control Loss Warning）"	V2V
5	5.2.10	"道路危险状况提示						  --Leve1
（HLW: Hazardous Location Warning）"	V2I
6	5.2.11	"限速预警								  --Leve1
（SLW：Speed Limit Warning）"	V2I
7	5.2.12	"闯红灯预警							  --Leve1
（Red Light Violation Warning）"	V2I
8	5.2.17	"紧急车辆提醒							  --Leve1
（EVW：Emergency Vehicle Warning）"	V2V/V2I
9	5.2.2	" 前向碰撞预警							  --Leve2
（FCW: Forward Collision Warning）"	V2V
10	5.2.4	"左转辅助								  --Leve2
（LTA：Left Turn Assist）"	V2V/V2I
11	5.2.5	"盲区预警、变道预警						  --Leve2
（Blind Spot Warning / Lane Change Warning）"	V2V
12	5.2.6	"逆向超车预警							  --Leve2
（Do Not Pass Warming)"	V2V
13	5.2.14	"绿波车速引导							  --Leve2
（GLOSA: Green Light Optimal Speed Advisory）"	V2P
14	5.2.15	"车内标牌								  --Leve1
（IVS：In-Vehicle Signage）"	V2I
15	5.2.16	"前方拥堵提醒							  --Leve2
（TJW: Traffic Jam Warning）"	V2I
 */
    typedef enum SceneType {

        SCENE_TYPE_ICW = 1, // 交叉路口碰撞预警
        SCENE_TYPE_EBW,     // 紧急制动预警
        SCENE_TYPE_AVW,     // 异常车辆提醒
        SCENE_TYPE_CLW,     // 车辆失控预警
        SCENE_TYPE_HLW,     // 道路危险状况提示
        SCENE_TYPE_SLW,     // 限速预警
        SCENE_TYPE_RLVW,    // 闯红灯预警
        SCENE_TYPE_EVW,     // 紧急车辆提醒
        SCENE_TYPE_FCW,     // 前向碰撞预警
        SCENE_TYPE_LTA,     // 左转辅助
        SCENE_TYPE_BSW_LCW, // 盲区预警、变道预警
        SCENE_TYPE_DNPW,    // 逆向超车预警
        SCENE_TYPE_GLOSA,   // 绿波车速引导
        SCENE_TYPE_IVS,     // 车内标牌
        SCENE_TYPE_TJW,     // 前方拥堵提醒
    }e_SceneType;

/*
| 报警优先级等级| 详细CASE
|--------------| ----------------------
|      7       | 追尾碰撞
|      7       | 正面碰撞
|      7       | 高速跟驰碰撞
|      7       | 低速跟驰碰撞
|      7       | 贴车碰撞
|      6       | 非低速刹车预警
|      6       | 低速刹车预警
|      6       | 变更车道附件有车
|      6       | 超车道上对面有来车
|      6       | 超车道上有前方同向慢车
|      6       | 超车道上有后方同向快车
|      7       | 短距离碰撞预警
|      7       | 短时间内碰撞预警
|      6       | 高速车辆预警
|      6       | 同方向车辆预警
|      6       | 对方减速碰撞预警
|      6       | 对方加速碰撞预警
|      6       | 对面直行预警
|      6       | 对面右转弯预警
|      3       | 占道提醒
|      3       | 交汇提醒
|      1       | 200M以上
|      1       | 100M以上
|      1       | 100米内
|      6       | 发送故障信息
|      6       | 故障车
|      6       | 发送ESP警告信息
|      6       | 接收ESP警告信息
|      5       | 自车倒车提示
|      5       | 前车倒车提示
|      1       | 交通信息提示
|      4       | 红灯警示报警
|      2       | 交通信号灯违规提醒
 */
    // 场景优先级（SRD中定义了7种优先级,11.2章节）
    typedef enum AlarmLevel{
        ALARM_LEVEL_1 = 1,
        ALARM_LEVEL_2,
        ALARM_LEVEL_3,
        ALARM_LEVEL_4,
        ALARM_LEVEL_5,
        ALARM_LEVEL_6,
        ALARM_LEVEL_7,
    }e_AlarmLevel;

    // 针对每个场景需要定义的属性
    union
    {
        HLWExt_t hlw;
        IVSExt_t ivs;
        SLWExt_t slw;
        RLVWExt_t rlvw;
        GLOSAExt_t glosa;
        TJWExt_t tjw;
    } u;

    e_SceneType getSceneType() const
    {
        return _sceneType;
    }
    void setSceneType(e_SceneType _sceneType)
    {
        V2xSceneMsg::_sceneType = _sceneType;
    }
    e_AlarmLevel getAlarmLevel() const
    {
        return _alarmLevel;
    }
    void setAlarmLevel(e_AlarmLevel _alarmLevel)
    {
        V2xSceneMsg::_alarmLevel = _alarmLevel;
    }
    DSecond_t getSecMark() const
    {
        return _sec_mark;
    }
    void setSecMark(DSecond_t secMark)
    {
        _sec_mark = secMark;
    }

    // for test
    typedef enum
    {
        LEVEL_1 = 1,
        LEVEL_2 = 2,
        LEVEL_3 = 3,
        LEVEL_4 = 4,
        LEVEL_5 = 5,
    } level_e;


    template<typename ...ArgTypes>
    V2xSceneMsg(ArgTypes &&...args)
        : string(std::forward<ArgTypes>(args)...)
    {
        TraceL << "创建V2xScene对象:" << this << " " << *this;
    };

    ~V2xSceneMsg()
    {
        DebugL << "销毁V2xScene对象:" << this << " " << *this;
    };

    level_e getLevel() const
    {
        return _level;
    }
    void setLevel(level_e level)
    {
        _level = level;
    }

private:
    e_SceneType _sceneType;
    e_AlarmLevel _alarmLevel;
    DSecond_t _sec_mark;
    // for test
    level_e _level;
};

}



#endif //V2XSCENE_H

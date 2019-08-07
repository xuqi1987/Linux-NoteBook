/* decription: v2x algorithm header filer
 * version			date				author			
 * 1.0(create)		2019/08/07			Xiao, Tianyao(YFVE)
*/

#ifndef V2XALGORITHM_H
#define V2XALGORITHM_H
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <ctime>
#include "V2xMsg.h"

namespace v2x {

const double PI = 3.1415926;

typedef enum
{
	//匀速直线行驶
	UNIFORM_STRAIGHT_LINE = 0,
	//匀变速直线行驶
	UNIFORM_VARIABLE_SPEED_LINE = 1,
	//匀速曲线行驶（圆弧）
	UNIFORM_VELOCITY_CURV = 2,
	//匀变速曲线行驶（抛物线）
	UNIFORM_VARIABLE_SPEED_CURV = 3,
	UNKNOWN_TYPE = 4
}LINETYPE;

typedef enum
{
	//正前
	V2X_FRONT = 0,
	//正后
	V2X_BACK = 1,
	//左前
	V2X_LEFT_FRONT = 2,
	//左后
	V2X_LEFT_BACK = 2,
	//右前
	V2X_RIGHT_FRONT = 3,
	//右后
	V2X_RIGHT_BACK = 4,
	//unknown
	V2X_UNKNOWN = 5
}DIRECTION;

class DriveLine
{
private:
	//常数项
	float m_Factor0;
	//一次方项系数
	float m_Factor1;
	//二次方项系数
	float m_Factor2;
	//三次方项系数--reserve
	float m_Factor3;
	//轨迹类型
	LINETYPE m_LineType;
	//轨迹预测开始timing
	tm m_startTime;
	//轨迹预测结束时间timing
	tm m_stopTime;
public:
	DriveLine(float factor0, float factor2, float factor3, LINETYPE lineType, tm startTime, tm stopTime);
	DriveLine(DriveLine& driveline);

	float getFactor0();
	float getFactor1();
	float getFactor2();
	float getFactor3();
	LINETYPE getLineType();
	tm getStartTime();
	tm getStopTime();
};


class ALGResult
{
protected:
	//HV和障碍物是否会发生碰撞
	bool m_IsCrash;
	/* 障碍物的 ID.
	 * RV: vehicle ID，
	 * RSI: local ID of this rsi information set by RSU
	 * SPAT: intersection ID
	*/
	string m_ObstacleId;
	//障碍物在HV的相对方向
	DIRECTION m_Direction;
	//HV距离障碍物的直线位移
	int32_t m_Distance;
	//HV 和障碍物碰撞的时刻
	tm m_CrashTiming;
public:
	const bool getCrashResult();
	const string getObstacleId();
	const DIRECTION getDirection();
	const int32_t getDistance();
	const tm getCrashTiming();
};

class ALGV2VResult : public ALGResult
{
private:
	//RV预测轨迹
	DriveLine m_DriveLineRV;
	//HV的预测轨迹
	DriveLine m_DriveLineHV;
	//HV相对于远车的速度大小
	int32_t m_RelativeSpeed;
public:
	const DriveLine getDriveLineRV();
	const DriveLine getDriveLineHV();
	const int32_t getRelativeSpeed();

	ERRNO setDriveLineRV(DriveLine &driveLine);
	ERRNO setDriveLineHV(DriveLine &driveLine);
	ERRNO setRelativeSpeed(int32_t relativeSpeed);

};

class ALGInterface
{
public:
	ALGResult getALGResult(V2xBSMMsg &HV_BsmMsg, V2xBSMMsg& RV_BsmMsg, V2xMapMsg& MapMsg);
	ALGResult getALGResult(V2xBSMMsg& HV_BsmMsg, V2xMapMsg& MapMsg, V2xSpatMsg& SpatMsg);
	ALGResult getALGResult(V2xBSMMsg& HV_BsmMsg, V2xBSMMsg& RV_BsmMsg , V2xMapMsg &MapMsg, V2xSpatMsg &SpatMsg);
	ALGResult getALGResult(V2xBSMMsg& HV_BsmMsg, V2xRsiMsg& RsiMsg);
	ALGResult getALGResult(V2xBSMMsg& HV_BsmMsg, V2xRsmMsg& RsmMsg);
};

class CrashDetect
{

};






class V2xAlgorithm
{
public:
//
   
private:

    
};

}



#endif //V2XALGORITHM_H

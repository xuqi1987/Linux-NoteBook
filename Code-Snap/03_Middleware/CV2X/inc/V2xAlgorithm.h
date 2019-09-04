/* decription: v2x algorithm header filer
 * version			date				author			
 * 1.0(create)		2019/08/07			Xiao, Tianyao(YFVE)
*/

#ifndef V2XALGORITHM_H
#define V2XALGORITHM_H
#include <stdint.h>
#include <ctime>
#include "V2xMsg.h"

namespace v2x {

/* 定义相对航向判定角度 */
#define REL_HEADING_JUDGE_ANGLE  15
/* 定义地球半径（unit/m） */
#define EARTH_RADIUS             6371393
/* 定义π值 */
#define PI                       3.1415926
/* 将角度转换为弧度 */
#define RADIAN(d)                ((d) * PI / 180.0)
/* 定义两车可能发生碰撞的距离 */
#define COLLISION_LENGTH_X       3
#define COLLISION_LENGTH_Y       3

#define POSITION_COUNTS_MAX 99

typedef enum RELATIVE_HEADING
{
    RELATIVE_HEADING_SAME = 0,  //同向
    RELATIVE_HEADING_OPPOSITE,  //对向
    RELATIVE_HEADING_CROSS      //交叉
} e_RELATIVE_HEADING;

typedef enum RELATIVE_DIRECTION
{
    RELATIVE_DIRECTION_FRONT = 0,   //正前
    RELATIVE_DIRECTION_LEFT_FRONT,  //左前
    RELATIVE_DIRECTION_RIGHT_FRONT, //右前
    RELATIVE_DIRECTION_REAR,        //正后
    RELATIVE_DIRECTION_LEFT_REAR,   //左后
    RELATIVE_DIRECTION_RIGHT_REAR,  //右后
    RELATIVE_DIRECTION_UNKNOWN
} e_RELATIVE_DIRECTION;

typedef enum DRIVE_INTENTION
{
    INTENTION_STRAIGHT = 0,
    INTENTION_TURN_LEFT,
    INTENTION_TURN_RIGHT,
    INTENTION_CHANGE_LANE_LEFT,
    INTENTION_CHANGE_LANE_RIGHT,
    INTENTION_TURN_AROUND,
    INTENTION_PARKING,
    INTENTION_UNKNOWN
} e_DRIVE_INTENTION;

typedef enum COLLISION_RISK_TYPE
{
    NON_COLLISION_RISK = 0,
    EXIST_COLLISION_RISK = 0,
    UNKNOWN_COLLISION_RISK
} e_COLLISION_RISK_TYPE;

typedef struct Coordinate
{
    double x;
    double y;
} Coordinate_t;

typedef struct TrackPoint
{
    Coordinate_t coordinate;
    double heading;
} TrackPoint_t;

typedef struct TrackPointList
{
    TrackPoint_t trackPointList[POSITION_COUNTS_MAX];
    int16_t length;
} TrackPointList_t;

typedef struct ProjectionXYs
{
    double minX;
    double minY;
    double maxX;
    double maxY;
} ProjectionXYs_t;

class V2xAlgorithm
{
public:
    V2xAlgorithm();

    /**
     * 计算相对航向角函数(用于计算两车相对航向)
     * @param hvHeading HV航向角
     * @param rvHeading RV航向角
     * @return
    */
    static double CalRelHeadingAngle(double hvHeading, double rvHeading);

    /**
     * 计算相对航向函数
     * @param hvHeading HV航向角
     * @param rvHeading RV航向角
     * @return 同向/对向/相交
    */
    static RELATIVE_HEADING CalRelativeHeading(double hvHeading, double rvHeading);

    /**
     * 坐标转化函数
     * 根据经纬度信息计算X方向（东西，东为正）、Y方向（南北，北为正）上两车相对距离
     * 利用Haversine法，参考https://blog.csdn.net/superrunner_wujin/article/details/79974661
     * @param hvLatitude HV纬度数值
     * @param hvLongitude HV经度数值
     * @param hvHeading HV航向角
     * @param rvLatitude RV纬度数值
     * @param rvLongitude RV经度数值
     * @param relCoordinate 返回以HV为原点（0，0），车头方向为Y轴的RV相对坐标
    */
    static void CalRelativeCoordinate(double hvLatitude,
                                      double hvLongitude,
                                      double hvHeading,
                                      double rvLatitude,
                                      double rvLongitude,
                                      Coordinate_t &relCoordinate);

    /**
     * 计算RV相对方位函数
     * @param rvRelCoordinate RV相对坐标(使用CalRelativeCoordinate函数获取)
     * @param hvWidth HV车宽 unit/m
     * @param rvWidth RV车宽 unit/m
     * @param hvConfidence HV位置精度 unit/m
     * @param rvConfidence RV位置精度 unit/m
     * @return 正前/左前/右前/正后/左后/右后
    */
    static RELATIVE_DIRECTION CalRelativeDirection(Coordinate_t &rvRelCoordinate,
                                                   double hvWidth,
                                                   double rvWidth,
                                                   double hvConfidence,
                                                   double rvConfidence);

    /**
     * 计算相对距离
     * 使用范围：仅用于计算RV与HV相对距离
     * @param relCoordinate RV相对坐标(使用CalRelativeCoordinate函数获取)
     * @return RV与HV相对距离 unit/m
    */
    static double CalDistance(Coordinate_t &relCoordinate);

    /**
     * 计算相对任意两点距离
     * http://blog.sina.com.cn/s/blog_5e7960620101vi0d.html
     * 适用范围：此方法适用于球面上任意两点间的距离求算，用高中数学知识即可证明此方法是球面余弦函数的一个变换，
     * 因为其中换掉了cos项，因此不存在短距离求算时对系统计算精度的过多顾虑的问题。
     * 已知两点经纬度，求两点间距离；Haversine法
     * @param hvLatitude HV纬度数值
     * @param hvLongitude HV经度数值
     * @param rvLatitude RV纬度数值
     * @param rvLongitude RV经度数值
     * @return RV与HV相对距离 unit/m
    */
    static double CalDistance(double hvLatitude, double hvLongitude, double rvLatitude, double rvLongitude);

    /**
     * 行车状态判断
     * @param turnSignal 信号灯信息（左转、右转）
     * @param speed 车速信息
     * @param steeringWheelAngle 方向盘转角
     * @param yawRate 横摆角速度
     * @param intersectionDistance 车辆与路口距离
     * @return RV与HV相对距离 unit/m
    */
    static DRIVE_INTENTION GetDriveIntetion(ExteriorLights turnSignal,
                                            double speed,
                                            double steeringWheelAngle,
                                            double yawRate,
                                            double intersectionDistance);

    /**
     * 轨迹预测函数-基于方向盘转角信息
     * @param steeringWheelAngle 方向盘转角(向右为正，向左为负 unit/°)
     * @param wheelBase 车辆轴距(unit/m)
     * @param steeringGearRatio 转向传动比
     * @param heading 初始航向角
     * @param coordinate 初始时刻位置
     * @param longSpeed 纵向车速
     * @param longAcceleration 纵向加速度
     * @param predictionTime 预测步长
     * @param predictionFreq 预测步长
     * @param tracePoints 预计结果
     * @return
    */
    static void TrackPrediction(double steeringWheelAngle,
                                double wheelBase,
                                double steeringGearRatio,
                                double heading,
                                Coordinate_t coordinate,
                                double longSpeed,
                                double longAcceleration,
                                int32_t predictionTime,
                                int32_t predictionFreq,
                                TrackPointList_t &tracePoints);

    /**
     * 轨迹预测函数-基于历史轨迹数据
     * @param historyPoints 历史轨迹
     * @param
     * @return
    */
    static void TrackPrediction(TrackPointList_t historyPoints,
                                double heading,
                                Coordinate_t coordinate,
                                double longSpeed,
                                double longAcceleration,
                                int32_t predictionTime,
                                int32_t predictionFreq,
                                TrackPointList_t &trackPoints);

    /**
     * 轨迹预测函数-基于横摆角速度
     * @param yawRate 横摆角速度(车辆横摆角速度 unit/(°/s))
     * @param
     * @return
    */
    static void TrackPrediction(double yawRate,
                                double heading,
                                Coordinate_t coordinate,
                                double longSpeed,
                                double longAcceleration,
                                int32_t predictionTime,
                                int32_t predictionFreq,
                                TrackPointList_t &tracePoints);

    /**
     * 车身投影坐标计算函数
     * @param vehicleWidth 车宽
     * @param vehicleHeight 车长
     * @param centroid 质心位置
     * @param heading 航向角
     * @return ProjectionPoint_t 投影得出的最小x,y值，最大X,Y值
    */
    static ProjectionXYs_t CalProjectiveXYs(double vehicleWidth, double vehicleHeight,Coordinate_t centroid, double heading);

    /**
     * 碰撞风险计算函数_质心位置差值法
     * 需保证两条轨迹步长相同，若HV、RV均由自车计算得到，则可以保证步长相同
     * 若RV预测轨迹序列由RV发送而来，则有可能存在步长不同的情况，可根据RV步长来确定HV预测序列，也可利用线性插值获得步长一致的预测序列
     * @param hvHistoryCoordinates HV预测轨迹序列
     * @param hvHistoryCoordinates RV预测轨迹序列
     * @return 不存在碰撞风险/存在碰撞风险/UNKNOWN
    */
    static COLLISION_RISK_TYPE CollisionRisk(TrackPointList_t hvProjectiveTrack, TrackPointList_t rvProjectiveTrack);

    /**
     * 碰撞风险计算函数_投影法
     * 借助车身投影坐标计算函数(CalProjectiveCoordinates)，计算每一位置点两车投影，看x和y方向上投影是否重合
     * @param
     * @return 不存在碰撞风险/存在碰撞风险/UNKNOWN
    */
    static COLLISION_RISK_TYPE CollisionRisk(TrackPointList_t hvProjectiveTrack,
                                             TrackPointList_t rvProjectiveTrack,
                                             double hvVehicleWidth,
                                             double hvVehicleHeight,
                                             double rvVehicleWidth,
                                             double rvVehicleHeight);


protected:
	void initlizeTimeStamp(tm* pTimeStamp);

private:
    /**
     * 向0取整函数
     * @param x
     * @return
    */
    static int fixToZero(double x);
};

}

#endif //V2XALGORITHM_H

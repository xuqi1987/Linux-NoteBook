/* decription: v2x algorithm header filer
 * version			date				author			
 * 1.0(create)		2019/08/09			Xiao, Tianyao(YFVE)
*/

#include "V2xAlgorithm.h"
#include <stdlib.h>
#include <math.h>
#include "V2xSetting.h"
#include <iostream>
#include "V2xUnitsDef.h"

namespace v2x {

	V2xAlgorithm::V2xAlgorithm()
	{
	}

	void V2xAlgorithm::initlizeTimeStamp(tm* pTimeStamp)
	{
		pTimeStamp->tm_year = 1970;
		pTimeStamp->tm_mon = 1;
		pTimeStamp->tm_mday = 1;
		pTimeStamp->tm_hour = 24;
		pTimeStamp->tm_min = 0;
        pTimeStamp->tm_sec = 0;
    }

    int V2xAlgorithm::fixToZero(double x)
    {
        if (x > 0)
        {
            x = floor(x);
        }
        else
        {
            x = ceil(x);
        }

        return x;
    }

    double V2xAlgorithm::CalRelHeadingAngle(double hvHeading, double rvHeading)
    {
        double theta = 0.0;
        if (rvHeading >= hvHeading)
        {
            theta = rvHeading - hvHeading;
        }
        else
        {
            theta = rvHeading - hvHeading + 360;
        }
        return theta;
    }

    RELATIVE_HEADING V2xAlgorithm::CalRelativeHeading(double hvHeading, double rvHeading)
    {
        double theta = CalRelativeHeading(hvHeading, rvHeading);
        RELATIVE_HEADING relativeHeading;

        if ((theta >= 0 && theta <= REL_HEADING_JUDGE_ANGLE)
            ||(theta >= (360 - REL_HEADING_JUDGE_ANGLE) && theta <= 360))
        {
            relativeHeading = RELATIVE_HEADING_SAME;
        }
        else if (theta >= (180 - REL_HEADING_JUDGE_ANGLE) && theta <= (180 + REL_HEADING_JUDGE_ANGLE))
        {
            relativeHeading = RELATIVE_HEADING_OPPOSITE;
        }
        else
        {
            relativeHeading = RELATIVE_HEADING_CROSS;
        }

        return relativeHeading;
    }

    void V2xAlgorithm::CalRelativeCoordinate(double hvLatitude,
                                             double hvLongitude,
                                             double hvHeading,
                                             double rvLatitude,
                                             double rvLongitude,
                                             Coordinate_t &relCoordinate)
    {
        //角度转弧度
        double radHvLat     = RADIAN(hvLatitude);
        double radHvLong    = RADIAN(hvLongitude);
        double radHvHeading = RADIAN(hvHeading);
        double radRvLat     = RADIAN(rvLatitude);
        double radRvLong    = RADIAN(rvLongitude);

        //根据经纬度信息计算X方向（东西，东为正）、Y方向（南北，北为正）上两车相对距离
        double x = 2 * EARTH_RADIUS * asin(cos(radRvLat)) * sin((radRvLong - radHvLong)/2.0);
        double y = EARTH_RADIUS * (radRvLat - radHvLat);

        //将距离坐标转化为以HV为原点，HV车头方向为Y轴的相对坐标
        relCoordinate.x = cos(radHvHeading) * y + sin(radHvHeading) * x;
        relCoordinate.y = -sin(radHvHeading) * y + cos(radHvHeading) * x;
    }

    RELATIVE_DIRECTION V2xAlgorithm::CalRelativeDirection(Coordinate_t &rvRelCoordinate,
                                                          double hvWidth,
                                                          double rvWidth,
                                                          double hvConfidence,
                                                          double rvConfidence)
    {
        RELATIVE_DIRECTION relDirection = RELATIVE_DIRECTION_UNKNOWN;
        double x = rvRelCoordinate.x;
        double y = rvRelCoordinate.y;

        //相对方位判断依据
        double deltaWidth = 0.5 * (hvWidth + rvWidth + hvConfidence + rvConfidence);

        if (y>0)
        {
            if (x > deltaWidth)
            {
                relDirection = RELATIVE_DIRECTION_RIGHT_FRONT;
            }
            else if (x < -deltaWidth)
            {
                relDirection = RELATIVE_DIRECTION_LEFT_FRONT;
            }
            else
            {
                relDirection = RELATIVE_DIRECTION_FRONT;
            }
        }
        else
        {
            if (x > deltaWidth)
            {
                relDirection = RELATIVE_DIRECTION_RIGHT_REAR;
            }
            else if (x < -deltaWidth)
            {
                relDirection = RELATIVE_DIRECTION_LEFT_REAR;
            }
            else
            {
                relDirection = RELATIVE_DIRECTION_REAR;
            }
        }
        return relDirection;
    }

    double V2xAlgorithm::CalDistance(Coordinate_t &relCoordinate)
    {
        double x = fabs(relCoordinate.x);
        double y = fabs(relCoordinate.y);

        double distance = sqrt(pow(x, 2) + pow(y, 2));

        return distance;
    }

    double V2xAlgorithm::CalDistance(double hvLatitude, double hvLongitude, double rvLatitude, double rvLongitude)
    {
        double radHvLat = RADIAN(hvLatitude);
        double radRvLat = RADIAN(rvLatitude);

        double radDiffLat = radHvLat - radRvLat;
        double radDiffLong = RADIAN(hvLongitude) - RADIAN(rvLongitude);

        //Haversine法
        double distance = 2 * EARTH_RADIUS * asin(sqrt(pow(sin(radDiffLat / 2), 2) + cos(radHvLat) * cos(radRvLat) * pow(sin(radDiffLong / 2), 2)));

        return distance;
    }

    //TBD, 需要根据速度、方向盘转角、横摆角速度优化此算法
    DRIVE_INTENTION V2xAlgorithm::GetDriveIntetion(ExteriorLights turnSignal,
                                                   double speed,
                                                   double steeringWheelAngle,
                                                   double yawRate,
                                                   double intersectionDistance)
    {
        DRIVE_INTENTION intention = INTENTION_UNKNOWN;
        if (turnSignal == ExteriorLights_leftTurnSignalOn)
        {
            if (intersectionDistance < 15)
            {
                intention = INTENTION_TURN_LEFT;
            }
            else
            {
                intention = INTENTION_CHANGE_LANE_LEFT;
            }
        }
        else if (turnSignal == ExteriorLights_rightTurnSignalOn)
        {

            if (intersectionDistance < 15)
            {
                intention = INTENTION_TURN_RIGHT;
            }
            else
            {
                intention = INTENTION_CHANGE_LANE_RIGHT;
            }
        }
        else if (turnSignal == ExteriorLights_parkingLightsOn)
        {
            if (speed == 0)
            {
                intention = INTENTION_PARKING;
            }
        }
        else
        {
            intention = INTENTION_STRAIGHT;
        }
        return intention;
    }

    void V2xAlgorithm::TrackPrediction(double steeringWheelAngle,
                                       double wheelBase,
                                       double steeringGearRatio,
                                       double heading,
                                       Coordinate_t coordinate,
                                       double longSpeed,
                                       double longAcceleration,
                                       int32_t predictionTime,
                                       int32_t predictionFreq,
                                       TrackPointList_t &trackPoints)
    {
        int32_t trackCount = (int32_t)predictionTime / predictionFreq;

        double headingStepper = (tan(RADIAN(steeringWheelAngle / steeringGearRatio)) / wheelBase * longSpeed * predictionFreq) * 180.0 / PI;

        if (trackCount >= POSITION_COUNTS_MAX)
        {
            trackCount = POSITION_COUNTS_MAX;
        }

        for (int32_t i = 0; i < trackCount; i++)
        {
            if (i == 0)
            {
                trackPoints.trackPointList[i].coordinate.x = coordinate.x + cos(RADIAN(heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].coordinate.y = coordinate.y + sin(RADIAN(heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].heading = heading + headingStepper;
            }
            else
            {
                trackPoints.trackPointList[i].coordinate.x =
                        trackPoints.trackPointList[i-1].coordinate.x + cos(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].coordinate.y =
                        trackPoints.trackPointList[i-1].coordinate.y + sin(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].heading = trackPoints.trackPointList[i-1].heading + headingStepper;
            }
            longSpeed = longSpeed + longAcceleration * predictionFreq;
        }
        trackPoints.length = trackCount;
    }

    void  V2xAlgorithm::TrackPrediction(TrackPointList_t historyPoints,
                                        double heading,
                                        Coordinate_t coordinate,
                                        double longSpeed,
                                        double longAcceleration,
                                        int32_t predictionTime,
                                        int32_t predictionFreq,
                                        TrackPointList_t &trackPoints)
    {
        int x1, y1, x2, y2, x3, y3;
        //定义圆点坐标
        double dotX, dotY;
        double steeringRadian;
        double steeringRadius;
        int hisPointsLength = historyPoints.length;

        int32_t trackCount;

        if (hisPointsLength < 3)
        {
            WarnL << "history track points less than 3, can't do TrackPrediction";
            return;
        }
        else
        {
            // 使用历史轨迹中最新的三个点
            x1 = historyPoints.trackPointList[hisPointsLength - 3].coordinate.x;
            y1 = historyPoints.trackPointList[hisPointsLength - 3].coordinate.y;
            x2 = historyPoints.trackPointList[hisPointsLength - 2].coordinate.x;
            y2 = historyPoints.trackPointList[hisPointsLength - 2].coordinate.y;
            x3 = historyPoints.trackPointList[hisPointsLength - 1].coordinate.x;
            y3 = historyPoints.trackPointList[hisPointsLength - 1].coordinate.y;

            trackCount = (int32_t)predictionTime / predictionFreq;

            if (trackCount >= POSITION_COUNTS_MAX)
            {
                trackCount = POSITION_COUNTS_MAX;
            }

            //近似认为此时车辆沿直线行驶
            if ((x1 == x2 && x2 == x3)
                || (y1 == y2 && y2 == y3)
                || (((x1 > x2 && x2 > x3 && y1 > y2 && y2 > y3) || (x1 < x2 && x2 < x3 && y1 < y2 && y2 < y3))
                    && ((((y2 - y1)/(x2 - x1) / (y3 - y2)/(x3 - x2)) > 0.95) && (((y2 - y1)/(x2 - x1) / (y3 - y2)/(x3 - x2)) < 1.05))))
            {
                steeringRadian = 0;
            }
            else //近似认为此时车辆沿圆周运动
            {
                //根据https://www.jianshu.com/p/ce61c421ffae所述公式计算当前转向半径
                /*******************************************************************
                设圆的公式如下：
                Ax²+Ay²+Bx+Cy+D=0;
                系数由如下行列式求得：
                A=x1(y2-y3)-y1(x2-x3)+x2x3-x3x2;
                B=(x1²+y1²)(y3-y2)+ (x2²+y2²)(y1-y3)+(x3²+y3²)(y2-y1);
                C=(x1²+y1²)(x2-x3)+ (x2²+y2²)(x3-x1)+(x3²+y3²)(x1-x2);
                D=(x1²+y1²)(x3y2-x2y3)+ (x2²+y2²)(x1y3-x3y1)+(x3²+y3²)(x2y1-x1y2);

                将圆方程化为标准方程：
                (x-(-B/(2A)))²+(y-(-C/(2A)))² = (sqrt((B²+C²-4AD)/(4A²)))²;
                将上述系数代入即可解得圆心(x,y)和半径R：
                x=-B/(2A);
                y=-C/(2A);
                r=sqrt((x-x1)²+(y-y1)²); //(x,y)为圆心
                r=sqrt((B²+C²-4AD)/(4A²));
                *******************************************************************/
                dotX = ((x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y2-y1))/(2*(x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2));
                dotY = ((x1*x1+y1*y1)*(x3-x2)+(x2*x2+y2*y2)*(x1-x3)+(x3*x3+y3*y3)*(x2-x1))/(2*(x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2));
                steeringRadius = sqrt((dotX-x1)*(dotX-x1)+(dotY-y1)*(dotY-y1));
                steeringRadian = 1/steeringRadius;
            }

            for (int32_t i = 0; i < trackCount; i++)
            {
                if (i == 0)
                {
                    trackPoints.trackPointList[i].coordinate.x = coordinate.x + cos(RADIAN(heading)) * longSpeed * predictionFreq;
                    trackPoints.trackPointList[i].coordinate.y = coordinate.y + sin(RADIAN(heading)) * longSpeed * predictionFreq;
                    trackPoints.trackPointList[i].heading = heading + (min(0.2, steeringRadian) * longSpeed * predictionFreq) * 180.0 / PI;
                }
                else
                {
                    trackPoints.trackPointList[i].coordinate.x =
                            trackPoints.trackPointList[i-1].coordinate.x + cos(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                    trackPoints.trackPointList[i].coordinate.y =
                            trackPoints.trackPointList[i-1].coordinate.y + sin(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                    trackPoints.trackPointList[i].heading =
                            trackPoints.trackPointList[i-1].heading + (min(0.2, steeringRadian) * longSpeed * predictionFreq) * 180.0 / PI;
                }
                longSpeed = longSpeed + longAcceleration * predictionFreq;
            }
            trackPoints.length = trackCount;
        }
    }

    void  V2xAlgorithm::TrackPrediction(double yawRate,
                                        double heading,
                                        Coordinate_t coordinate,
                                        double longSpeed,
                                        double longAcceleration,
                                        int32_t predictionTime,
                                        int32_t predictionFreq,
                                        TrackPointList_t &trackPoints)
    {
        int32_t trackCount = (int32_t)predictionTime / predictionFreq;
        if (trackCount >= POSITION_COUNTS_MAX)
        {
            trackCount = POSITION_COUNTS_MAX;
        }

        for (int32_t i = 0; i < trackCount; i++)
        {
            if (i == 0)
            {
                trackPoints.trackPointList[i].coordinate.x = coordinate.x + cos(RADIAN(heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].coordinate.y = coordinate.y + sin(RADIAN(heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].heading = heading + yawRate * predictionFreq;
            }
            else
            {
                trackPoints.trackPointList[i].coordinate.x =
                        trackPoints.trackPointList[i-1].coordinate.x + cos(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].coordinate.y =
                        trackPoints.trackPointList[i-1].coordinate.y + sin(RADIAN(trackPoints.trackPointList[i].heading)) * longSpeed * predictionFreq;
                trackPoints.trackPointList[i].heading = trackPoints.trackPointList[i-1].heading + yawRate * predictionFreq;
            }
            longSpeed = longSpeed + longAcceleration * predictionFreq;
        }
        trackPoints.length = trackCount;
    }

    ProjectionXYs_t V2xAlgorithm::CalProjectiveXYs(double vehicleWidth, double vehicleHeight, Coordinate_t centroid, double heading)
    {
        //定义车身四点位置
        double xlf, ylf, xlr, ylr, xrf, yrf, xrr, yrr;
        double headingRadian = RADIAN(heading);
        double beta = atan(vehicleWidth/vehicleHeight);
        double raduis = sqrt(0.25*(vehicleWidth*vehicleWidth + vehicleHeight*vehicleHeight));

        ProjectionXYs_t projectionXYs;

        (void)memset(&projectionXYs, 0x00, sizeof(ProjectionXYs_t));

        //计算车身四点位置
        xlf = centroid.x + raduis * sin(headingRadian + beta);
        ylf = centroid.y + raduis * cos(headingRadian + beta);
        xlr = centroid.x + raduis * sin(headingRadian - beta);
        ylr = centroid.y + raduis * cos(headingRadian - beta);
        xrf = centroid.x - raduis * sin(headingRadian + beta);
        yrf = centroid.y - raduis * cos(headingRadian + beta);
        xrr = centroid.x - raduis * sin(headingRadian - beta);
        yrr = centroid.y - raduis * cos(headingRadian - beta);

        //根据车身四点位置确定minX,minY,maxX,maxY
        projectionXYs.minX = min(min(xlf, xlr), min(xrf, xrr));
        projectionXYs.minY = min(min(ylf, ylr), min(yrf, yrr));
        projectionXYs.maxX = max(max(xlf, xlr), max(xrf, xrr));
        projectionXYs.maxY = max(max(ylf, ylr), max(yrf, yrr));

        return projectionXYs;
    }

    COLLISION_RISK_TYPE V2xAlgorithm::CollisionRisk(TrackPointList_t hvProjectiveTrack, TrackPointList_t rvProjectiveTrack)
    {
        COLLISION_RISK_TYPE collisionRisk = NON_COLLISION_RISK;

        int diffX, diffY;

        if (hvProjectiveTrack.length < 1 || rvProjectiveTrack.length < 1)
        {
            ErrorL << "projecttive track less than one, can't do CollisionRisk calculate";
            collisionRisk = UNKNOWN_COLLISION_RISK;
        }
        else if (hvProjectiveTrack.length != rvProjectiveTrack.length)
        {
            ErrorL << "projecttive track length should be same";
            collisionRisk = UNKNOWN_COLLISION_RISK;
        }
        else
        {
            for (int i = 0; i < hvProjectiveTrack.length; i++)
            {
                diffX = fixToZero(hvProjectiveTrack.trackPointList[i].coordinate.x - rvProjectiveTrack.trackPointList[i].coordinate.x);
                diffY = fixToZero(hvProjectiveTrack.trackPointList[i].coordinate.y - rvProjectiveTrack.trackPointList[i].coordinate.y);
                if ((abs(diffX) < COLLISION_LENGTH_X) && (abs(diffY) < COLLISION_LENGTH_Y))
                {
                    DebugL << "Difference method find collision risk at point " << i;
                    collisionRisk = EXIST_COLLISION_RISK;
                    break;
                }
            }
        }

        DebugL << "Difference method collisionRisk = " << collisionRisk;
        return collisionRisk;
    }

    COLLISION_RISK_TYPE V2xAlgorithm::CollisionRisk(TrackPointList_t hvProjectiveTrack,
                                                    TrackPointList_t rvProjectiveTrack,
                                                    double hvVehicleWidth,
                                                    double hvVehicleHeight,
                                                    double rvVehicleWidth,
                                                    double rvVehicleHeight)
    {
        COLLISION_RISK_TYPE collisionRisk = NON_COLLISION_RISK;

        ProjectionXYs_t hvProjectionXYs;
        ProjectionXYs_t rvProjectionXYs;

        if (hvProjectiveTrack.length < 1 || rvProjectiveTrack.length < 1)
        {
            ErrorL << "projecttive track less than one, can't do CollisionRisk calculate";
            collisionRisk = UNKNOWN_COLLISION_RISK;
        }
        else if (hvProjectiveTrack.length != rvProjectiveTrack.length)
        {
            ErrorL << "projecttive track length should be same";
            collisionRisk = UNKNOWN_COLLISION_RISK;
        }
        else
        {
            for (int i = 0; i < hvProjectiveTrack.length; i++)
            {
                hvProjectionXYs = CalProjectiveXYs(hvVehicleWidth,
                                                   hvVehicleHeight,
                                                   hvProjectiveTrack.trackPointList[i].coordinate,
                                                   hvProjectiveTrack.trackPointList[i].heading);
                rvProjectionXYs = CalProjectiveXYs(rvVehicleWidth,
                                                   rvVehicleHeight,
                                                   rvProjectiveTrack.trackPointList[i].coordinate,
                                                   rvProjectiveTrack.trackPointList[i].heading);

                if (rvProjectionXYs.minX > hvProjectionXYs.maxX
                    || rvProjectionXYs.minY > hvProjectionXYs.maxY
                    || rvProjectionXYs.maxX < hvProjectionXYs.minX
                    || rvProjectionXYs.maxY < hvProjectionXYs.minY)
                {
                    collisionRisk = NON_COLLISION_RISK;
                }
                else
                {
                    DebugL << "Projection method find collision risk at point " << i;
                    collisionRisk = EXIST_COLLISION_RISK;
                    break;
                }
            }
        }

        DebugL << "Projection method collisionRisk = " << collisionRisk;
        return collisionRisk;
    }
}




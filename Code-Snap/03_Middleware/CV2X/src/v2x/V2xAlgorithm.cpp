//
// Created by xuqi on 2019-07-17.
//

#include "V2xAlgorithm.h"

double v2x::V2xAlgorithm::lonlat2dis(Longitude_t lon1, Latitude_t lat1, Longitude_t lon2, Latitude_t lat2)
{
    //R = 6371.004;%km
    double R = 6371.004;

    //distance = pi*R*acos(sin(lat1).*sin(lat2)+cos(lat1).*cos(lat2).*cos(long2-long1))/180;
    return 0;
}

bool v2x::V2xAlgorithm::isLRrear(long lon_hv, long lat_hv, float heading_hv, long lon_rv, long lat_rv)
{
//    angle = (450-heading_hv)/180*pi;
//    e = [cos(angle),sin(angle)];
//    delta_long = long_rv - long_hv;
//    delta_lat = lat_rv - lat_hv;
//    delta_dir = [delta_long,delta_lat];
//    %水平坐标分量
//        para = sum(e.*delta_dir);
//    %正交经纬度差
//        orth_delta = delta_dir-para*e;
//    orth_dis = 1000*lonlat2dis(long_hv,lat_hv,long_hv+orth_delta(1),lat_hv+orth_delta(2));%单位:m
//    if para<0&&orth_dis>4.5%depends on vehicle size
//    islrrear = 1;
//    else
//    islrrear = 0;
//    end

    return false;
}

bool v2x::V2xAlgorithm::isFront(long lon_hv, long lat_hv, float heading_hv, long lon_rv, long lat_rv)
{
//    angle = (450-heading_hv)/180*pi;
//    e = [cos(angle),sin(angle)];
//    delta_long = long_rv - long_hv;
//    delta_lat = lat_rv - lat_hv;
//    delta_dir = [delta_long,delta_lat];
//    %水平坐标分量
//        para = sum(e.*delta_dir);
//    %正交经纬度差
//        orth_delta = delta_dir-para*e;
//    orth_dis = 1000*lonlat2dis(long_hv,lat_hv,long_hv+orth_delta(1),lat_hv+orth_delta(2));%单位:m
//    if para>0&&orth_dis<4.5%orth_dis<4.5 depends on vehicle size
//    isfront = 1;
//    else
//    isfront = 0;
//    end
    return false;
}

int v2x::V2xAlgorithm::fcw_level(long lon_hv,
                                 long lat_hv,
                                 long heading_hv,
                                 long speed_hv,
                                 long lon_rv,
                                 long lat_rv,
                                 float heading_rv,
                                 long speed_rv)
{
//    %warning_level = 'fcw_info';
//    ttc_info = 3;%单位:second
//    ttc_advi = 2.5;
//    ttc_immi = 2;
//
//    %采用二维向量模型进行计算
//    delta_degree = [long_hv-long_rv,lat_hv-lat_rv];
//    angle_hv = (450-heading_hv)/180*pi;
//    e_hv = [cos(angle_hv),sin(angle_hv)];
//    angle_rv = (450-heading_rv)/180*pi;
//    e_rv = [cos(angle_rv),sin(angle_rv)];
//    delta_speed = (speed_hv*e_hv-speed_rv*e_rv)/3.6;%单位:m/s
//    R = 6371.004;%km
//        delta_position = delta_degree*pi*R*1000/180;%单位：m
//        ttc = -1*sum(delta_position.*delta_speed)/norm(delta_speed)/norm(delta_speed);
//    min_distance = norm(delta_position+ttc*delta_speed);
//    if min_distance<3 && ttc>0
//    if ttc<ttc_immi
//    warning_level = 'fcw_immi';
//    else if ttc<ttc_advi
//    warning_level = 'fcw_advi';
//    else if ttc<ttc_info
//    warning_level = 'fcw_info';
//    else
//    warning_level = 0;
//    end
//        end
//    end
//    else
//    warning_level = 0;
//    end

    return 0;
}
double v2x::V2xAlgorithm::lonlat2dis(v2x::V2xBSMMsg &bsm1, v2x::V2xBSMMsg &bsm2)
{

   return lonlat2dis(bsm1.getLongitude(),bsm1.getLatitude(),bsm2.getLongitude(),bsm2.getLatitude());;
}
bool v2x::V2xAlgorithm::isLRrear(v2x::V2xBSMMsg &bsm1, v2x::V2xBSMMsg &bsm2)
{
    return false;
    //return isLRrear();
}
bool v2x::V2xAlgorithm::isFront(v2x::V2xBSMMsg &bsm1, v2x::V2xBSMMsg &bsm2)
{
    return false;
    //return isFront();
}





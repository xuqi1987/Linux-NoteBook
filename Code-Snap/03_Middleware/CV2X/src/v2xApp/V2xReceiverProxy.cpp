//
// Created by xuqi on 2019-08-06.
//

#include <V2xMsg.h>
#include "V2xReceiverProxy.h"


namespace v2x {

void V2xReplayReceiver::init()
{
    string path = SET["Debug.ReplayerFilePath"].as<string>();
    DebugL << "Log回放，读取log文件:" <<path;
    _csv = make_shared<CSVReader<7>>(path);

    _csv->read_header(io::ignore_extra_column, "TempId","LogRecType","secMark","lat", "long","heading","speed");

}
bool V2xReplayReceiver::recv(V2xMsg::ValuePtr &&msg)
{
    string type;
    uint32_t id;
    unsigned  int secMark;
    double lat;
    double lon;
    double heading;
    double speed;
    _csv->read_row(id,type,secMark, lat,lon,heading,speed);

    TraceL <<" "<<id <<" " << type<< " " <<secMark<<" " <<lat<<" " <<lon<< " " <<heading<< " " <<speed<< endl;
    if (type == "TX")
    {
        msg->setMsgType(V2xMsg::MSG_TYPE_HV_BSM);
        msg->u.hvbsm.secMark = secMark;
        msg->u.hvbsm.id = id;
        msg->u.hvbsm.pos.lat = lat * 1000 * 1000;
        msg->u.hvbsm.pos.lon = lon * 1000 * 1000;
        msg->u.hvbsm.heading = heading;
        msg->u.hvbsm.speed = speed;

    }
    else if(type == "RX")
    {
        msg->setMsgType(V2xMsg::MSG_TYPE_RV_BSM);
        msg->u.rvbsm.secMark = secMark;
        msg->u.rvbsm.id = id;
        msg->u.rvbsm.pos.lat = lat * 1000 * 1000;
        msg->u.rvbsm.pos.lon = lon * 1000 * 1000;
        msg->u.rvbsm.heading = heading;
        msg->u.rvbsm.speed = speed;
    }
    usleep(1000*1);
    return true;

}

void V2xSavariReceiver::init()
{

}
bool V2xSavariReceiver::recv(V2xMsg::ValuePtr &&msg)
{

}

void V2xReceiverProxy::init()
{
    if (SET["Debug.ScenceReplayFlag"].as<bool>())
    {
        TraceL << "new V2xReplayReceiver::init" << endl;
        _receiver = make_shared<V2xReplayReceiver>();
    }
    else
    {
        TraceL << "new V2xSavariReceiver::init" << endl;
        _receiver = make_shared<V2xSavariReceiver>();
    }
    _receiver->init();

}
bool V2xReceiverProxy::recv(V2xMsg::ValuePtr &&msg)
{
    return _receiver->recv(move(msg));
}
}

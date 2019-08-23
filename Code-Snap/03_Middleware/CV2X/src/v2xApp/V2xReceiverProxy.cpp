//
// Created by xuqi on 2019-08-06.
//

#include <V2xMsg.h>
#include "V2xReceiverProxy.h"


namespace v2x {

void V2xReplayReceiver::Init()
{
    string path = SET["Debug.ReplayerFilePath"].as<string>();
    DebugL << "Log回放，读取log文件:" <<path;
    _csv = make_shared<CSVReader<7>>(path);

    _csv->read_header(io::ignore_extra_column, "TempId","LogRecType","secMark","lat", "long","heading","speed");

}
bool V2xReplayReceiver::Recv(V2xMsg::ValuePtr &&pMsg)
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
        pMsg->SetMsgType(V2xMsg::MSG_TYPE_HV_BSM);
        pMsg->u.hvbsm.secMark = secMark;
        pMsg->u.hvbsm.id = id;
        pMsg->u.hvbsm.pos.lat = lat * 1000 * 1000;
        pMsg->u.hvbsm.pos.lon = lon * 1000 * 1000;
        pMsg->u.hvbsm.heading = heading /1000 * 1000 /0.0125;
        pMsg->u.hvbsm.speed = speed / 0.02 / 3.6;

    }
    else if(type == "RX")
    {
        pMsg->SetMsgType(V2xMsg::MSG_TYPE_RV_BSM);
        pMsg->u.rvbsm.secMark = secMark;
        pMsg->u.rvbsm.id = id;
        pMsg->u.rvbsm.pos.lat = lat * 1000 * 1000;
        pMsg->u.rvbsm.pos.lon = lon * 1000 * 1000;
        pMsg->u.rvbsm.heading = heading /1000 * 1000 /0.0125;
        pMsg->u.rvbsm.speed = speed / 0.02 / 3.6;
    }

    static uint32_t lastsecMark = secMark;
    int t = secMark-lastsecMark;
    if (t < 0) t= 0;
    if (t > 200) t =200;
    usleep(100*t);
    lastsecMark = secMark;

    return true;

}

void V2xSavariReceiver::Init()
{

}
bool V2xSavariReceiver::Recv(V2xMsg::ValuePtr &&pMsg)
{

}

void V2xReceiverProxy::Init()
{
    if (SET["Debug.ScenceReplayFlag"].as<bool>())
    {
        TraceL << "new V2xReplayReceiver::Init" << endl;
        m_pReceiver = make_shared<V2xReplayReceiver>();
    }
    else
    {
        TraceL << "new V2xSavariReceiver::Init" << endl;
        m_pReceiver = make_shared<V2xSavariReceiver>();
    }
    m_pReceiver->Init();

}
bool V2xReceiverProxy::Recv(V2xMsg::ValuePtr &&pMsg)
{
    return m_pReceiver->Recv(move(pMsg));
}
}

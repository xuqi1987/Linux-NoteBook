//
// Created by root on 19-8-7.
//

#ifndef CV2X_V2XHVMAPSPATCAL_H
#define CV2X_V2XHVMAPSPATCAL_H


#include "V2xBroker.h"
#include "V2xAlgorithmTest.h"


namespace v2x
{

class V2xHvMapSpatCal
{
public:
    typedef shared_ptr<V2xHvMapSpatCal> Ptr;
    V2xHvMapSpatCal(const shared_ptr<V2xBroker> &pBroker);
    void run();

    typedef enum
    {
        RELATIVE_DIRECTION_UNKOWN = 0,
        RELATIVE_DIRECTION_FRONT = 1,
        RELATIVE_DIRECTION_REAR = 2
    } EN_RELATIVE_DIRECTION;

private:
    V2xBroker::Ptr m_pBroker;
    V2xAlgorithmTest   m_algorithm;
    VehicleSize_t   m_stRsuSize;

    //Define V2I scene function
    //Hazardous Location Warning
    void HLWarning(V2xMsg::ValuePtr in_pMsg);
    //Speed Limit Warning
    void SLWarning(V2xMsg::ValuePtr in_pMsg);
    //Red Light Violation Warning
    void RLVWarning(V2xMsg::ValuePtr in_pMsg);
    //Emergency Vehicle Warning
    void EVWarning(V2xMsg::ValuePtr in_pMsg);
    //Green Light Optimal Speed Advisory
    void GLOSA(V2xMsg::ValuePtr in_pMsg);
    //In-Vehicle Signage
    void IVS(V2xMsg::ValuePtr in_pMsg);
    //Traffic Jam Warning
    void TJWarning(V2xMsg::ValuePtr in_pMsg);
    //Computing the relative direction of HV and RSU
    EN_RELATIVE_DIRECTION GetHVAndRSURelDirection(V2xMsg::ValuePtr in_pHVMsg, V2xMsg::ValuePtr in_pRSUMsg);
};

}


#endif //CV2X_V2XHVMAPSPATCAL_H

//
// Created by xuqi on 2019-07-13.
//

#include <v2x/V2xMsg.h>
#include "V2xGNSSProducer.h"
#include "test/TestGNSSProducer.h"

using namespace test;


V2xGNSSProducer::V2xGNSSProducer(Queue::Ptr &queue)
    : Producer()
{
    _hv_gnss_pool.setSize(100);
    _hv_gnss_queue = queue;
}

V2xGNSSProducer::~V2xGNSSProducer()
{

}

void V2xGNSSProducer::run()
{

    while (1) {
        ValuePtr gnss = _hv_gnss_pool.obtain();

        gnss->assign("");
        gnss->setMsgType(V2xMsg::MSG_TYPE_GNSS);

        TestGNSSProducer::Inst().update();
        gnss->u.hvgnss.setSpeed(TestGNSSProducer::Inst().getSpeed());
        gnss->u.hvgnss.setHeading(TestGNSSProducer::Inst().getHeading());
        gnss->u.hvgnss.setLongitude(TestGNSSProducer::Inst().getLongitude());
        gnss->u.hvgnss.setLatitude(TestGNSSProducer::Inst().getLatitude());

        gnss->Print();
        _hv_gnss_queue->push(gnss);

        usleep(1000 * 1000);

    }
}

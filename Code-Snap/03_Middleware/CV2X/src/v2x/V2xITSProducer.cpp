//
// Created by root on 19-7-12.
//

#include <v2x/V2xMsg.h>
#include "V2xITSProducer.h"
#include "test/TestITSProducer.h"

using namespace test;

V2xITSProducer::V2xITSProducer(Queue::Ptr &queue)
    : Producer()
{
    _rv_bsm_pool.setSize(100);
    _rv_bsm_queue = queue;
}

V2xITSProducer::~V2xITSProducer()
{
    ErrorL << "析构V2xITSProducer";
}

// 接收数据的线程
void V2xITSProducer::run()
{


    while (1) {

        ValuePtr rv_bsm = _rv_bsm_pool.obtain();
        rv_bsm->setMsgType(V2xMsg::MSG_TYPE_RV_BSM);

        TestITSProducer::Inst().update();

        rv_bsm->u.hvbsm.setTempId(TestITSProducer::Inst().getId());
        rv_bsm->u.hvbsm.setSecMark(TestITSProducer::Inst().getSecMark());
        rv_bsm->u.hvbsm.setLatitude(TestITSProducer::Inst().getLatitude());
        rv_bsm->u.hvbsm.setLongitude(TestITSProducer::Inst().getLongitude());
        rv_bsm->u.hvbsm.setHeading(TestITSProducer::Inst().getHeading());
        rv_bsm->u.hvbsm.setSpeed(TestITSProducer::Inst().getSpeed());

        rv_bsm->assign(StrPrinter << rv_bsm->u.hvbsm.getTempId());

        rv_bsm->Print();

        _rv_bsm_queue->push(rv_bsm);

        usleep(1000 * 1000);

    }
}




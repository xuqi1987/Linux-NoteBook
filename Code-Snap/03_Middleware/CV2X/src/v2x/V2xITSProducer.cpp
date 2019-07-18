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
    _tmp_rv_bsm_queue = make_shared<V2xITSProducer::Queue>();

    _filter = make_shared<V2xRvBsmFilter>(10, _tmp_rv_bsm_queue, _rv_bsm_queue);
}

V2xITSProducer::~V2xITSProducer()
{
    ErrorL << "析构V2xITSProducer";
}

// 接收数据的线程
void V2xITSProducer::run()
{

    _filter->start();

    while (1) {

        ValuePtr rv_bsm = _rv_bsm_pool.obtain();
        rv_bsm->setMsgType(V2xMsg::MSG_TYPE_RV_BSM);

        TestITSProducer::Inst().update();

        rv_bsm->u.rvbsm.setTempId(TestITSProducer::Inst().getTempId());
        rv_bsm->u.rvbsm.setSecMark(TestITSProducer::Inst().getTempId());
        rv_bsm->u.rvbsm.setLatitude(TestITSProducer::Inst().getLatitude());
        rv_bsm->u.rvbsm.setLongitude(TestITSProducer::Inst().getLongitude());
        rv_bsm->u.rvbsm.setHeading(TestITSProducer::Inst().getHeading());
        rv_bsm->u.rvbsm.setSpeed(TestITSProducer::Inst().getSpeed());

        rv_bsm->assign(StrPrinter << rv_bsm->u.rvbsm.getTempId());

        rv_bsm->Print();

        _tmp_rv_bsm_queue->push(rv_bsm);

        usleep(1000 * 1000);

    }
}




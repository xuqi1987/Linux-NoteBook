//
// Created by root on 19-7-11.
//

#include "V2xApp.h"


namespace v2x
{

V2xApp::V2xApp()
{

}

void V2xApp::run()
{
    this->createProducer();
    usleep(1000 * 10);
    this->createBroker();

}

void V2xApp::createProducer()
{

    _its_out_pool = make_shared<V2xITSProducer::Queue>();
    _its_producer = make_shared<V2xITSProducer>(_its_out_pool);

    _gnss_out_pool = make_shared<V2xGNSSProducer::Queue>();
    _gnss_producer = make_shared<V2xGNSSProducer>(_gnss_out_pool);

    _can_out_pool = make_shared<V2xCANProducer::Queue>();
    _can_producer = make_shared<V2xCANProducer>(_can_out_pool);

    _gnss_producer->start();
    usleep(1000 * 10);
    _its_producer->start();
    usleep(1000 * 10);
    _can_producer->start();

}

void V2xApp::createBroker()
{
    auto &_filter_in_pool = _its_out_pool;
    // 对数据进行 过滤器
    _filter_out_pool = make_shared<V2xRvBsmFilter::Queue>();
    _filter = make_shared<V2xRvBsmFilter>(10, _filter_in_pool, _filter_out_pool);
    _filter->start();
}

void V2xApp::createConsumer()
{

}

}

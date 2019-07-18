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

    _rv_data_pool = make_shared<V2xITSProducer::Queue>();
    _rv_producer = make_shared<V2xITSProducer>(_rv_data_pool);

    _hv_data_pool = make_shared<V2xGNSSProducer::Queue>();
    _hv_producer = make_shared<V2xGNSSProducer>(_hv_data_pool);


    _hv_producer->start();
    usleep(1000 * 10);
    _rv_producer->start();

}

void V2xApp::createBroker()
{

}

void V2xApp::createConsumer()
{

}

}

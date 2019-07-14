//
// Created by root on 19-7-11.
//

#include "V2xApp.h"



namespace v2x
{

V2xApp::V2xApp() {


}

void V2xApp::run()
{
  this->createProducer();
  this->createBroker();

}

void V2xApp::createProducer() {

  _its_out_pool = make_shared< V2xITSProducer::Queue>();
  // 生产者
  _its_producer = make_shared<V2xITSProducer>(_its_out_pool);
  _its_producer->start();



}

void V2xApp::createBroker() {

  auto & _filter_in_pool = _its_out_pool;

  // 对数据进行 过滤器
  _filter_out_pool = make_shared<V2xFilter::Queue>();
  _filter = make_shared<V2xFilter> (10,_filter_in_pool,_filter_out_pool);

  _filter->start();

}

void V2xApp::createConsumer() {

}

}

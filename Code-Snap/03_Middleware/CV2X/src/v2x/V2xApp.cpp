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


  _its_out_pool = make_shared< V2xITSProducer::Queue>();

  // 生产者
  _its_producer = make_shared<V2xITSProducer>(_its_out_pool);
  _its_producer->start();

  auto & _filter_in_pool = _its_out_pool;

  // 过滤器
  _filter_out_pool = make_shared<V2xFilter::Queue>();
  _filter = make_shared<V2xFilter> (10,_filter_in_pool,_filter_out_pool);

  _filter->start();

}


void V2xApp::runRVFilterThread(int i)
{
    V2xITSProducer::ValuePtr oneCar;

    while (1) {
        //bool ret = _its_out_pool->pop(oneCar);
        //DebugL << _its_out_pool;
        //InfoL << "线程( "<<i<< " )\t从pool中拿到数据处理，数据内容是：" << *oneCar << " 地址是：" << oneCar;
        //InfoL <<i ;
        //oneCar.reset();
        sleep(1);
    }
}

void V2xApp::runCANRecvThread()
{
    while (1) {
//      V2xITSProducer::ValuePtr oneCar;
//      bool ret = _its_producer->pop(oneCar);
//
//      InfoL << "拿到数据处理，数据内容是:"<< oneCar <<"返回值" << ret;
//        sleep(1);
    }
}

}

//
// Created by root on 19-7-11.
//

#include "V2xApp.h"



namespace v2x
{
void V2xApp::run()
{
    // 设置总共资源187个
    _cars_pool.setSize(187);
    // 设置线程池
    _thread_pool = make_shared<ThreadPool>(20,ThreadPool::PRIORITY_HIGHEST, false);

    _thread_pool->async(bind(&V2xApp::runGNSSThread,this));

    for(int i = 0; i < 10; i++)
    {
      _thread_pool->async(bind(&V2xApp::runRVFilterThread,this,i));
    }

    _thread_pool->async(bind(&V2xApp::runCANRecvThread,this));

    _thread_pool->start();
}

void V2xApp::runGNSSThread()
{

     while (1) {
         static int count = 0;

         count++;
         auto car = _cars_pool.obtain();
         string info = StrPrinter << "车辆数据包 No." << count;

         car->assign(info);
         DebugL << "新数据包来了 No." << count << " 放入地址：" << car;

         _recv_queue.push(car);
         usleep(1000*20);

     }

}

void V2xApp::runRVFilterThread(int i)
{
    decltype(_cars_pool)::ValuePtr oneCar;

    while (1) {
        bool ret = _recv_queue.get_data(oneCar);
        DebugL << "线程( "<<i<< " )\t从pool中拿到数据处理，数据内容是：" << *oneCar << " 地址是：" << oneCar;
        oneCar.reset();
        sleep(1);
    }
}

void V2xApp::runCANRecvThread()
{

}
}

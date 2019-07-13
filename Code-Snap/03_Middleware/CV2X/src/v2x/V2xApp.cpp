//
// Created by root on 19-7-11.
//

#include "V2xApp.h"



namespace v2x
{

V2xApp::V2xApp() {
  _its_producer = make_shared<V2xITSProducer>();

  // 设置线程池
  _thread_pool = make_shared<ThreadPool>(20,ThreadPool::PRIORITY_HIGHEST, false);
}

void V2xApp::run()
{

    _its_producer->start();

    for(int i = 0; i < 10; i++)
    {
      _thread_pool->async(bind(&V2xApp::runRVFilterThread,this,i));
    }


    _thread_pool->start();


}

void V2xApp::runITSThread()
{

//     while (1) {
//         static int count = 0;
//
//         count++;
//         auto car = _othercars_pool.obtain();
//         string info = StrPrinter << "车辆数据包 No." << count;
//
//         car->assign(info);
//         DebugL << "新数据包来了 No." << count << " 放入地址：" << car;
//
//       _recv_queue.push(car);
//         usleep(1000*50);
//
//     }

}

void V2xApp::runRVFilterThread(int i)
{
//    decltype(_othercars_pool)::ValuePtr oneCar;
//
//    while (1) {
//        bool ret = _recv_queue.get_data(oneCar);
//        InfoL << "线程( "<<i<< " )\t从pool中拿到数据处理，数据内容是：" << *oneCar << " 地址是：" << oneCar;
//
//        oneCar.reset();
//        sleep(1);
//    }
}

void V2xApp::runCANRecvThread()
{
    while (1) {
      InfoL << "更新自车信息=====";
        sleep(1);
    }
}

}

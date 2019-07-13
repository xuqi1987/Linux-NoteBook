//
// Created by root on 19-7-12.
//

#include "V2xITSProducer.h"
V2xITSProducer::V2xITSProducer() : Producer()
{
     // 国标周边车187辆
    _othercars.setSize(187);
}

V2xITSProducer::~V2xITSProducer()
{
    ErrorL << "析构V2xITSProducer";
}
bool V2xITSProducer::get(V2xcar::Ptr car)
{
     return  _data_queue.get_data(car);
}

// 接收数据的线程
void V2xITSProducer::recv() {


  while (1) {
    static int count = 0;

    count++;
    auto car = _othercars.obtain();
    string info = StrPrinter << "车辆数据包 No." << count;

    car->assign(info);
    DebugL << "新数据包来了 No." << count << " 放入地址：" << car;

    _data_queue.push(car);
    usleep(1000*50);

  }
}
//
// Created by root on 19-7-12.
//

#include "V2xITSProducer.h"

V2xITSProducer::~V2xITSProducer()
{
    ErrorL << "析构V2xITSProducer";
}

// 接收数据的线程
void V2xITSProducer::recv() {


  while (1) {
    static int count = 0;

    count++;
    ValuePtr car = _othercars.obtain();
    string info = StrPrinter << "车辆数据包 No." << count;

    car->assign(info);
    DebugL << "新数据包来了 No." << count << " 放入地址：" << car;

    _data_queue->push(car);

    usleep(1000*1000);

  }
}

V2xITSProducer::V2xITSProducer(Queue::Ptr &queue)
: Producer() {
  // 国标周边车187辆
  _othercars.setSize(187);
  _data_queue = queue;
}


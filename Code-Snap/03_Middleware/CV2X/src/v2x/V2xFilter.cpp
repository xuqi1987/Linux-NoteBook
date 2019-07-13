//
// Created by xuqi on 2019-07-13.
//

#include "V2xFilter.h"

V2xFilter::V2xFilter(int threadnum, Queue::Ptr &iQueue,Queue::Ptr &oQueue)
:Broker(10)
{
  _input_queue = iQueue;
  _output_queue = oQueue;

}

void V2xFilter::work(int num) {

  ValuePtr oneCar;

  while (1) {
    bool ret = _input_queue->pop(oneCar);

    InfoL << "线程( "<<num<<" )\t从pool中拿到数据处理，数据内容是：" << *oneCar << " 地址是：" << oneCar;

    if (num %2 == 0)
    {
      TraceL << "过滤掉的数据" << *oneCar << "数据地址: " << oneCar ;
      oneCar.reset();

    }
    else
    {
      TraceL << "需要的数据，放入下一个队列" << *oneCar << "数据地址: " << oneCar ;
      _output_queue->push(oneCar);
    }

    sleep(1);
  }
}

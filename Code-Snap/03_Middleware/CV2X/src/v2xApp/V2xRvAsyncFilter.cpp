//
// Created by xuqi on 2019-07-13.
//

#include "V2xRvAsyncFilter.h"
namespace v2x
{
V2xRvAsyncFilter::V2xRvAsyncFilter(int iThreadNum, Queue::Ptr &pIn_Queue, Queue::Ptr &pOut_Queue)

{
  m_pInputQueue = pIn_Queue;
  m_pOutputQueue = pOut_Queue;

}

void V2xRvAsyncFilter::Run(int num)
{

  ValuePtr oneCar;

  while (1) {
    bool ret = m_pInputQueue->pop(oneCar);

    TraceL << "线程( " << num << " )\t从pool中拿到数据处理，数据内容是：" << *oneCar << " 地址是：" << oneCar;

    if (oneCar->u.rvbsm.speed > 5) {
      DebugL << "过滤掉的数据，速度大于5" << *oneCar << "数据地址: " << oneCar;
      oneCar.reset();

    }
    else {
      TraceL << "需要的数据，放入下一个队列" << *oneCar << "数据地址: " << oneCar;
      m_pOutputQueue->push(move(oneCar));
    }

    sleep(1);
  }
}
}

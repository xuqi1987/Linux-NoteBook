//
// Created by root on 19-7-12.
//

#include "V2xITSProducer.h"
V2xITSProducer::V2xITSProducer()
{
     // 国标周边车187辆
     V2xITSProducer(187);
}

V2xITSProducer::V2xITSProducer(int objnum)
{
     _othercars.setSize(objnum);
}

V2xITSProducer::~V2xITSProducer()
{

}
bool V2xITSProducer::get(V2xcar::Ptr car)
{
     return  _data_queue.get_data(car);

}
void V2xITSProducer::startWorking()
{

}

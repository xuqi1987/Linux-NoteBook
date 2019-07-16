//
// Created by root on 19-7-12.
//

#include "Producer.h"
Producer::Producer() {
  _thread = make_shared<ThreadPool>(1,ThreadPool::PRIORITY_HIGHEST,false);
}
Producer::~Producer() {

}
void Producer::start() {

  _thread->async(bind(&Producer::run,this));
  _thread->start();
}

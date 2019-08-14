//
// Created by xuqi on 2019-08-13.
//

#include "Util/Util.h"
#include "Util/Logger.h"
#include <iostream>
using namespace toolkit;
using  namespace std;


class Obj {
 public:

  Obj() { WarnL << "Obj"; }
  ~Obj() { WarnL << "~Obj";}
 private:


};
class Msg : public noncopyable
{
 public:
  Msg() {
    WarnL << "Msg";
    obj = new Obj();}

  ~Msg() {
    delete obj;
    WarnL << "~Msg";
  }
 private:
  Obj *obj;
};


void fun1(Msg msg)
{

}

void fun2(Msg &&msg)
{

}

int main()
{

  Logger::Instance().add(std::make_shared<ConsoleChannel>());

  Msg msg;

  // noncopyable 无法通过编译
  // Msg msg2 = msg;
  // fun1(msg);

  fun2(std::move(msg));
return 0;
}
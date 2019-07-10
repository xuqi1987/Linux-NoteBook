/*
 * MIT License
 *
 * Copyright (c) 2016-2019 xiongziliang <771730766@qq.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <signal.h>
#include <iostream>
#include <random>
#include "Util/util.h"
#include "Util/logger.h"
#include "Util/ResourcePool.h"
#include <list>

using namespace std;
using namespace toolkit;

class string_imp : public string {
 public:
  template<typename ...ArgTypes>
  string_imp(ArgTypes &&...args) : string(std::forward<ArgTypes>(args)...) {
    DebugL << "创建string对象:" << this << " " << *this;
  };
  ~string_imp() {
    WarnL << "销毁string对象:" << this << " " << *this;
  }
};

int main() {
  //初始化日志
  Logger::Instance().add(std::make_shared<ConsoleChannel>());
  Logger::Instance().setWriter(std::make_shared<AsyncLogWriter>());
  {
    //大小为50的循环池
    ResourcePool<string_imp> pool;
    pool.setSize(2);

    //获取一个对象,该对象将被主线程持有，并且不会被后台线程获取并赋值
    auto reservedObj = pool.obtain();

    reservedObj.reset();

    {
      WarnL << "主线程打印:开始测试主动放弃循环使用功能";

      std::list<decltype(pool)::ValuePtr> objlist;
      for (int i = 0; i < 4; ++i) {
        reservedObj = pool.obtain();
        string str = StrPrinter << i << " " << (i % 2 == 0 ? "此对象将脱离循环池管理" : "此对象将回到循环池");
        reservedObj->assign(str);
        reservedObj.quit(i % 2 == 0);
        objlist.emplace_back(reservedObj);
      }

    }
    ErrorL << "循环结束没有放回池中的对象都被析构，进入池的对象不会析构⬆";
  }
  ErrorL << "pool退出，析构pool中的对象⬆";

  return 0;
}












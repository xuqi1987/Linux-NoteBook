#include <iostream>
#include "Util/logger.h"
#include "Util/ResourcePool.h"
#include "v2x/msgqueue.h"
#include "v2x/v2xcar.h"

#include <thread>
#include <future>

using namespace std;
using namespace v2x;
using namespace toolkit;

int main()
{
    Logger::Instance().add(make_shared<ConsoleChannel>());

    ResourcePool<V2xcar> cars_pool;
    cars_pool.setSize(187);

    MsgQueue<V2xcar> recv_queue;

    std::async(std::launch::async,[&]() {
        while(1)
        {
            static int count = 0;

            count ++;
            auto car = cars_pool.obtain();
            string info = StrPrinter << "This is Car No." << count;
            car->assign(info);

            WarnL << *car;
            //recv_queue.push(std::move(car));
            sleep(1);
        }

    });


    return 0;
}
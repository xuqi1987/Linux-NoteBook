//
// Created by root on 19-7-11.
//

#include "V2xApp.h"



namespace v2x
{
void V2xApp::run()
{
    cars_pool.setSize(187);
    this->runGNSSThread();
    sleep(1);
    this->runRVFilterThread();
    this->runCANRecvThread();
}

void V2xApp::runGNSSThread()
{
    static std::thread revc([&]()
                     {
                         while (1) {
                             static int count = 0;

                             count++;
                             auto car = cars_pool.obtain();
                             string info = StrPrinter << "This is Car No." << count;
                             car->assign(info);

                             recv_queue.push(car);
                             sleep(1);
                             WarnL << "loop End";
                         }
                     });
}

void V2xApp::runRVFilterThread()
{
    decltype(cars_pool)::ValuePtr oneCar;

    while (1) {
        bool ret = recv_queue.get_data(oneCar);
        WarnL << "Get -------->" << oneCar << *oneCar;
        oneCar.reset();
        sleep(2);
    }
}

void V2xApp::runCANRecvThread()
{

}
}

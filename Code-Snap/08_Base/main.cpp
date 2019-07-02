#include <iostream>     // std::cout
#include <future>       // std::packaged_task, std::future
#include <chrono>       // std::chrono::seconds
#include <thread>       // std::thread, std::this_thread::sleep_for
#include "ThreadPool.h"

void test(std::string str)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << __func__<< str << std::this_thread::get_id() <<std::endl;

}

void test1()
{

}

// count down taking a second for each value:
int countdown (int from, int to) {
    for (int i=from; i!=to; --i) {
        std::cout << i << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Finished!\n";
    return from - to;
}

int main ()
{
    ThreadPool threadPool(5);
    threadPool.enqueue(countdown,5,1);
    threadPool.enqueue(countdown,10,5);
    threadPool.enqueue(countdown,15,10);
    threadPool.enqueue(countdown,20,15);
    threadPool.enqueue(countdown,25,20);
    threadPool.enqueue(countdown,30,25);

    return 0;
}
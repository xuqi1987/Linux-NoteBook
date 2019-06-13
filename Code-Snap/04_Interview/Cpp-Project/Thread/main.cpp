#include <iostream>
#include <thread>

#include <string.h>


int main() {
    std::cout << "Hello, World!" << std::endl;



    int a = 0;
    auto f = [&] () {a++;};
    f();

    std::cout <<a <<std::endl;
    return 0;
}
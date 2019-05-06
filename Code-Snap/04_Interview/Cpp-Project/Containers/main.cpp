#include <iostream>
#include "SequenceContainer.h"
#include "Type.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    SequenceContainer::Instance()->ArrayDemo();
    SequenceContainer::Instance()->VectorDemo();
    return 0;
}
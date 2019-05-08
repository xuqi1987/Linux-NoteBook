#include <iostream>
#include "SequenceContainer.h"
#include "AssociativeContainers.h"

#include "Type.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    SequenceContainer::Instance()->ArrayDemo();
    SequenceContainer::Instance()->VectorDemo();
    SequenceContainer::Instance()->ListDemo();

    std::cout <<std::endl<< "========================================================" <<std::endl;
    AssociativeContainers::Instance()->setmapDemo();

    return 0;
}
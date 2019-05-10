#include <iostream>
#include "SequenceContainer.h"
#include "AssociativeContainers.h"
#include "ContainerAdaptor.h"
#include "Type.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    SequenceContainer::Instance()->ArrayDemo();
    SequenceContainer::Instance()->VectorDemo();
    SequenceContainer::Instance()->ListDemo();

    std::cout <<std::endl<< "========================================================" <<std::endl;
    AssociativeContainers::Instance()->setmapDemo();
    AssociativeContainers::Instance()->multiDemo();
    AssociativeContainers::Instance()->unorderedDemo();

    ContainerAdaptor::Instance()->stackDemo();
    ContainerAdaptor::Instance()->queueDemo();

    return 0;
}
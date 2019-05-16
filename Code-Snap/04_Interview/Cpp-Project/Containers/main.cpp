#include <iostream>
#include "SequenceContainer.h"
#include "AssociativeContainers.h"
#include "ContainerAdaptor.h"
#include "Type.h"
#include "AlgorithmSTL.h"

int main() {
    std::cout <<std::endl<< "===========================容器=============================" <<std::endl;
    SequenceContainer::Instance()->ArrayDemo();
    SequenceContainer::Instance()->VectorDemo();
    SequenceContainer::Instance()->ListDemo();


    AssociativeContainers::Instance()->setmapDemo();
    AssociativeContainers::Instance()->multiDemo();
    AssociativeContainers::Instance()->unorderedDemo();

    ContainerAdaptor::Instance()->stackDemo();
    ContainerAdaptor::Instance()->queueDemo();

    std::cout <<std::endl<< "============================算法============================" <<std::endl;
    AlgorithmSTL::Instance()->nonModifySequenceOpe();


    return 0;
}
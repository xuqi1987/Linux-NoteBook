//
// Created by root on 19-5-8.
//

#include "AssociativeContainers.h"

#include <set>
#include <map>
#include <iostream>
#include "Type.h"

AssociativeContainers::AssociativeContainers() {}

AssociativeContainers::~AssociativeContainers() {

}

AssociativeContainers *AssociativeContainers::Instance() {
    static AssociativeContainers sInst;
    return &sInst;
}

void AssociativeContainers::setmapDemo() {
    int ary[] = {1,2,3,4,5,6};
    std::set<int> sA(ary,ary+ sizeof(ary)/sizeof(int));
    for(std::set<int>::iterator it = sA.begin(); it != sA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    PC(sA)

}

void AssociativeContainers::multiDemo() {

}

void AssociativeContainers::unorderedDemo() {

}

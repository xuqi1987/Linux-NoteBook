//
// Created by root on 19-5-6.
//

#include "SequenceContainer.h"
#include <array>
#include <iostream>
#include <algorithm>
#include "Type.h"

SequenceContainer::SequenceContainer() {}

SequenceContainer::~SequenceContainer() {

}

void SequenceContainer::ArrayDemo() {
    // 初始化
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,0};
    std::array<struA, 3> arrb;

    arrb.fill({'a',1,1}); // array 

    // 获取（访问）元素
    std::for_each(arr.begin(), arr.end(), [](int &i){i++;});

    for(auto i : arr){
        std::cout << i << " ";
    }
    std::cout <<std::endl;

    for (auto j :arrb){
        std::cout << j.c << std::endl;
    }


}

void SequenceContainer::DequeDemo() {

}

void SequenceContainer::Forward_listDemo() {

}

void SequenceContainer::ListDemo() {

}

SequenceContainer *SequenceContainer::Instance() {
    static SequenceContainer sInst;
    return &sInst;
}

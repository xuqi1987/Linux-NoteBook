//
// Created by root on 19-5-6.
//

#include "SequenceContainer.h"
#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Type.h"
#include <vector>

using namespace std;

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
        std::cout << j.c << " ";
    }
    std::cout <<std::endl;

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

void SequenceContainer::VectorDemo() {

    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {1,2,3,4};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;

    std::vector<struA> v1;

    for (vector<int>::reverse_iterator it = fifth.rbegin(); it != fifth.rend(); ++it)
    {
        cout << " "<<*it;
    }

}


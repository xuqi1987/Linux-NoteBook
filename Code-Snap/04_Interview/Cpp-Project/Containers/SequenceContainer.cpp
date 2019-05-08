//
// Created by root on 19-5-6.
//

#include "SequenceContainer.h"
#include <array>
#include <iostream>

#include <vector>
#include "Type.h"
#include <vector>
#include <list>

using namespace std;


SequenceContainer::SequenceContainer() {}

SequenceContainer::~SequenceContainer() {

}

void SequenceContainer::ArrayDemo() {
    //支持快速随机访问
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


void SequenceContainer::ListDemo() {
    int ary[] = {1,2,3,4,5};
    std::list<int> lA(ary,ary + sizeof(ary)/ sizeof(int));

    std::cout << std::endl;
    std::cout << "List Demo:" ;

    for (auto &i : lA)
    {
        std::cout << i++ << " ";
    }

    std::cout << std::endl;

    for(std::list<int>::iterator it = lA.begin();it != lA.end(); ++it)
    {
        std::cout << *it<< " ";
    }

    std::cout << std::endl;

    std::for_each(lA.begin(),lA.end(),[](const auto &i) {std::cout << i << " ";});

    std::cout << std::endl;
    // Element access
    lA.front() = lA.back();

    std::for_each(lA.begin(),lA.end(),[](const auto &i) {std::cout << i << "\t";});

    double darry[] = {0.1,1.2,0.9,1.4,1.7,1.2};
    std::list<double> lB(darry,darry + sizeof(darry) / sizeof(double));

    PC(lB)

    lB.sort();
    PC(lB)

    lB.reverse();
    PC(lB)

    lB.unique();
    PC(lB)

    lB.remove(1.2);
    PC(lB)

    double darry2[] = {2.3,4.3};
    std::list<double> lC(darry2,darry2+sizeof(darry2)/ sizeof(double));

    lB.merge(lC);

    lB.remove_if([](const auto & i){return i > 1;});
    PC(lB)

    
}

SequenceContainer *SequenceContainer::Instance() {
    static SequenceContainer sInst;
    return &sInst;
}

void SequenceContainer::VectorDemo() {

    // 随机读改、尾部插入、尾部删除 O(1)
    //头部插入、头部删除 O(n)
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


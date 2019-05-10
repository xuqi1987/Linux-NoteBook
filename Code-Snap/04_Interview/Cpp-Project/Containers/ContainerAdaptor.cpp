//
// Created by root on 19-5-10.
//

#include "ContainerAdaptor.h"
#include <stack>
#include <queue>
#include <iostream>
#include <list>

ContainerAdaptor::ContainerAdaptor() {}

void ContainerAdaptor::stackDemo() {

    int ary[] = {1,2,3,4,5,6,7};
    std::vector<int> vA(ary,ary+ sizeof(ary)/ sizeof(int));
    //deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时
    std::stack<int,std::vector<int>> sA(vA);

    std::deque<int> dA(ary,ary+ sizeof(ary)/ sizeof(int));

    std::stack<int> sB(dA);

    sA.push(10);

    std::cout << std::endl;

    while(!sA.empty())
    {
        std::cout << sA.top() << " ";
        sA.pop(); // pop from list end
    }
    std::cout << std::endl;

}

void ContainerAdaptor::queueDemo() {
    int ary[] = {1,2,3,4,5,6,7};
    std::deque<int> dA(ary,ary+ sizeof(ary)/sizeof(int));

    std::list<int> lA(ary,ary+ sizeof(ary)/sizeof(int));

    std::queue<int> qA(dA);
    std::queue<int,std::list<int> > qB(lA);

    while(!qA.empty())
    {
        std::cout << qA.front() <<  " ";
        qA.pop(); // pop from list header
    }


}

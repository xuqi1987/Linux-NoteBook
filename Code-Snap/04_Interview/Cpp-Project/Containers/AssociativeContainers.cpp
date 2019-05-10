//
// Created by root on 19-5-8.
//

#include "AssociativeContainers.h"

#include <set>
#include <map>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "Type.h"

using namespace std;

AssociativeContainers::AssociativeContainers() {}

AssociativeContainers::~AssociativeContainers() {

}

AssociativeContainers *AssociativeContainers::Instance() {
    static AssociativeContainers sInst;
    return &sInst;
}

void AssociativeContainers::setmapDemo() {
    int ary[] = {2,3,4,5,6,7};
    std::set<int> sA(ary,ary+ sizeof(ary)/sizeof(int));

    for(std::set<int>::iterator it = sA.begin(); it != sA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    PC(sA)


    sA.insert(1);

    PC(sA)

    std::set<int>::iterator i;
    i = sA.find(3);

    std::cout << "\nFind: "<<*i << std::endl;

    sA.insert(i,0);//有序，所以会重排，无法插入指定位置

    PC(sA)

    std::map<std::string,int> mA;
    mA["a"] = 1;
    mA["b"] = 2;
    mA["c"] = 3;

    PCM(mA)

    mA.insert(std::pair<std::string, int>("d",4));

    PCM(mA)

    std::map<std::string,int>::iterator it3 = mA.find("a");

    mA.insert(it3, std::pair<std::string, int>("e",5));
    if (it3 != mA.end())
        mA.erase(it3);

    PCM(mA)
}

void AssociativeContainers::multiDemo() {
    int arry[] = {1,2,3,4,5,6,7,1,2};
    std::multiset<int> msA(arry,arry + sizeof(arry)/ sizeof(int));
    PC(msA)

    std::multiset<int>::iterator it = msA.find(1);
    std::cout << *it;

}

void AssociativeContainers::unorderedDemo() {
    std::unordered_map<char,int> umA;


    umA.insert(std::pair<char,int>('b',2));
    umA.insert(std::pair<char,int>('a',1));

    umA.insert(std::pair<char,int>('c',3));

    umA.insert({{'e',6},{'f',7}});

    PCM(umA)

    std::unordered_map<char,int>::const_iterator it = umA.find('b');
    if (it == umA.end())
    {
        std::cout << "not find"<<std::endl;
    } else
    {
        std::cout << "\n"<<it->first << it->second << std::endl;
    }

    //umA.insert(umA.end(),std::pair<char,int>('d',4));

    PCM(umA)
}

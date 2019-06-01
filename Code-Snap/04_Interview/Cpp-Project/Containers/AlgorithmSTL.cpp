//
// Created by xuqi on 2019-05-16.
//

#include "AlgorithmSTL.h"
#include "Type.h"
AlgorithmSTL::AlgorithmSTL() {}

AlgorithmSTL *AlgorithmSTL::Instance() {
    static AlgorithmSTL Inst;
    return &Inst;
}

void AlgorithmSTL::nonModifySequenceOpe() {

    int ary[] = {1,2,3,4,5,6,7,8,9,0,0,1,0};
    std::vector<int> v(ary, ary+ sizeof(ary)/sizeof(int));

    if (std::all_of(v.begin(),v.end(),[](int i){return i > -1 ;}))
    {
        P("All > -1")
    }


    if(std::find(v.begin(),v.end(),2) != v.end())
    {
        P("find OK")
    }

    std::vector<int>::iterator it = v.begin();
    it = std::find_if(it,v.end(),[](int i){ return  i > 5;});

    P(*it)

    int ary2[] = {7,8,9};
    it = std::find_end(v.begin(), v.end(),ary2,ary2 + sizeof(ary2)/sizeof(int));

    if (it != v.end())
    {
        P2("find end at pos: ",it - v.begin())
    }

    //
    it = std::find_end(v.begin(), v.end(),ary2,ary2+sizeof(ary2)/sizeof(int),[](int i,int j) {return i > j;});

    if (it != v.end()) P2("find at pos:", it - v.begin())

    char mychars[] = {'a','b','c','d'};
    char needle[] = {'A','B','C'};

    std::vector<char> v2(mychars, mychars + sizeof(mychars)/sizeof(char));

    std::vector<char>::iterator it2 = std::find_first_of(v2.begin(),v2.end(),needle,needle + sizeof(needle)/sizeof(char),[](char a,char b){
        return (std::tolower(a) == std::tolower(b));
    });
    P2("find in mychars:  ",*it2)


    it = std::adjacent_find(v.begin(),v.end(),[](int i,int j){return i == j;});

    if (it != v.end())
    {
        P2("找到连续重复的两个:",*it)
    }


    int count = std::count(v.begin(),v.end(),1);
    P2("找到X个:",count);



}

void AlgorithmSTL::modifySequenceOpe() {

}

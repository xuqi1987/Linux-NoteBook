//
// Created by xuqi on 2019-05-16.
//

#ifndef CONTAINERS_ALGORITHMSTL_H
#define CONTAINERS_ALGORITHMSTL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

class AlgorithmSTL {


public:
    static AlgorithmSTL* Instance();

    void nonModifySequenceOpe();
    void modifySequenceOpe();
private:
    AlgorithmSTL();
};


#endif //CONTAINERS_ALGORITHMSTL_H

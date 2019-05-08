//
// Created by root on 19-5-6.
//

#ifndef CONTAINERS_TYPE_H
#define CONTAINERS_TYPE_H

#include <algorithm>


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef double u64;

typedef struct struA {
    u8 a;
    u16 b;
    u32 c;
};

class classA {
public:

    u32 getM_A() const {
        return m_A;
    }

    classA(u32 m_A) : m_A(m_A) {}

    virtual ~classA() {}

private:
    u32 m_A;

};

#define PC(v) std::cout << std::endl; \
            std::for_each(v.begin(),v.end(),[](const auto &d){std::cout << d <<" \t ";});
#endif //CONTAINERS_TYPE_H

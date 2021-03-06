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


#define P(v) std::cout << std::endl; \
                        std::cout <<__func__ <<" : ["<<__LINE__<<"]" << " ";                     \
                        std::cout << v <<" "<<std::endl;
#define P2(v1,v2) std::cout << std::endl; \
                        std::cout <<__func__ <<" : ["<<__LINE__<<"]" << " ";                     \
                        std::cout << v1 << "   "<<v2<<std::endl;

#define PC(v) std::cout << std::endl; \
                        std::cout <<__func__ <<" : ["<<__LINE__<<"]" << " ";                     \
            std::for_each(v.begin(),v.end(),[](const auto &d){std::cout << d <<" ";});

#define PCM(v) std::cout << std::endl; \
                        std::cout <<__func__ <<" : ["<<__LINE__<<"]" << " "; \
                        std::for_each(v.begin(),v.end(),[](const auto &d){std::cout << d.first  << ":"<< d.second <<"\t";});


#endif //CONTAINERS_TYPE_H

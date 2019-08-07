//
// Created by xuqi on 2019-08-07.
//

#ifndef V2XRVTHREADPOOL_H
#define V2XRVTHREADPOOL_H
#include "V2xThreadPool.h"

namespace v2x {


class V2xRvThreadPool : public V2xThreadPool
{
public:
    void run(int num) override;
};

}


#endif //V2XRVTHREADPOOL_H

//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XSENDER_H
#define V2XSENDER_H
#include "V2xThread.h"

namespace v2x {
class V2xSender : public V2xThread
{
public:
    typedef shared_ptr<V2xSender> Ptr;
    void run() override;
};

}
#endif //V2XSENDER_H

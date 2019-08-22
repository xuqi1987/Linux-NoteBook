//
// Created by root on 19-8-8.
//

#ifndef CV2X_V2XCAROBJECTMGNT_H
#define CV2X_V2XCAROBJECTMGNT_H
#include "V2xThread.h"


namespace v2x {

class V2xCarObjectMgnt : public V2xThread
{
public:

    void Run() override;
};

}




#endif //CV2X_V2XCAROBJECTMGNT_H

//
// Created by root on 19-8-5.
//

#ifndef CV2X_V2XDATAREPLAYER_H
#define CV2X_V2XDATAREPLAYER_H
#include "v2xUtil/V2xThread.h"
#include <string>
#include "Util/Logger.h"

namespace v2x {

class V2xDataReplayer : public V2xThread
{
public:
    void loadData();
    V2xDataReplayer();
    ~V2xDataReplayer() override;
    void run() override;

private:
};

}



#endif //CV2X_V2XDATAREPLAYER_H

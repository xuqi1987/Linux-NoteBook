//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XCAR_H
#define CV2X_V2XCAR_H
#include <string>
#include "Util/Logger.h"

using namespace std;
using namespace toolkit;

namespace v2x {

class V2xcar : public string
{
public:
    template<typename ...ArgTypes>
    V2xcar(ArgTypes &&...args) : string(std::forward<ArgTypes>(args)...){
        DebugL << "创建V2XCar对象:" << this << " " << *this;
    };
    ~V2xcar() {
        WarnL << "销毁string对象:" << this << " " << *this;
    }
};

}


#endif //CV2X_V2XCAR_H

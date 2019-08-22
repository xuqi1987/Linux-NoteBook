//
// Created by root on 19-8-20.
//

#ifndef CV2X_V2XEXCEPTION_H
#define CV2X_V2XEXCEPTION_H
#include <exception>
#include <memory>
#include <typeinfo>


namespace v2x {

#define NULL_CHECK(p) typeid(*p)
}


#endif //CV2X_V2XEXCEPTION_H

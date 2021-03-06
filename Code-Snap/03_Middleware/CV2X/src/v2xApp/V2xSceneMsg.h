//
// Created by xuqi on 2019-07-23.
//

#ifndef V2XSCENE_H
#define V2XSCENE_H
#include <string>
#include "Util/Logger.h"
#include "v2xStack/V2xType.h"
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsgQueue.h"

using namespace std;
using namespace toolkit;

namespace v2x {

class V2xSceneMsg: public string
{
public:

    typedef shared_ptr<V2xSceneMsg> Ptr;
    typedef RecycleResourcePool<V2xSceneMsg> Pool;
    typedef RecycleResourcePool<V2xSceneMsg>::ValuePtr ValuePtr;
    typedef V2xMsgQueue<ValuePtr> Queue;

    typedef enum
    {
        LEVEL_1 = 1,
        LEVEL_2 = 2,
        LEVEL_3 = 3,
        LEVEL_4 = 4,
        LEVEL_5 = 5,
    } level_e;


    template<typename ...ArgTypes>
    V2xSceneMsg(ArgTypes &&...args)
    : string(std::forward<ArgTypes>(args)...)
    {
        TraceL << "创建V2xScene对象:" << this << " " << *this;
    };

    ~V2xSceneMsg()
    {
        DebugL << "销毁V2xScene对象:" << this << " " << *this;
    };

    level_e getLevel() const
    {
        return _level;
    }
    void setLevel(level_e level)
    {
        _level = level;
    }

    DSecond_t getSecMark() const
    {
        return _sec_mark;
    }
    void setSecMark(DSecond_t secMark)
    {
        _sec_mark = secMark;
    }
private:
    level_e _level;
    DSecond_t _sec_mark;


};

}



#endif //V2XSCENE_H

//
// Created by root on 19-8-30.
//

#include "NoticeCenter.h"
namespace toolkit {

NoticeCenter &NoticeCenter::Instance(){
    static NoticeCenter instance;
    return instance;
}

}
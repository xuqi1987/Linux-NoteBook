//
// Created by xuqi on 2019-07-02.
//

#ifndef UTIL_H
#define UTIL_H


namespace toolkit
{


#define INSTANCE_IMP(class_name, args...) \
class_name & class_name::Inst() { \
    static auto s_pInst = std::make_shared<class_name>(args); \
    static class_name & ref = *s_pInst; \
    return ref; \
}

// 禁止拷贝构造函数
class noncopyable
{
protected:
    noncopyable(){};
    ~noncopyable(){};
private:
    noncopyable(const noncopyable &that) = delete;
    noncopyable(noncopyable &&that) = delete;

    noncopyable &operator=(const noncopyable &that) = delete;
    noncopyable &operator=(noncopyable &&that) = delete;
};

class util
{

};
}


#endif //UTIL_H

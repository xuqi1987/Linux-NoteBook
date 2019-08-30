
//
// Created by root on 19-8-30.
//

#ifndef CV2X_NOTICECENTER_H
#define CV2X_NOTICECENTER_H
#include <mutex>
#include <memory>
#include <string>
#include <exception>
#include <functional>
#include <unordered_map>
#include "function_traits.h"

namespace toolkit {

class NoticeCenter {
public:
    class InterruptException : public std::runtime_error
    {
    public:
        InterruptException():std::runtime_error("InterruptException"){}
        ~InterruptException(){}
    };

    ~NoticeCenter(){}
    static NoticeCenter &Instance();

    template<typename ...ArgsType>
    bool emitEvent(const string &strEvent,ArgsType &&...args){
        decltype(_mapListener)::mapped_type listenerMap;
        {
            lock_guard<recursive_mutex> lck(_mtxListener);
            auto it0 = _mapListener.find(strEvent);
            if (it0 == _mapListener.end()) {
                return false;
            }
            listenerMap = it0->second;
        }
        for(auto &pr : listenerMap){
            typedef function<void(decltype(std::forward<ArgsType>(args))...)> funType;
            funType *obj = (funType *)(pr.second.get());
            try{
                (*obj)(std::forward<ArgsType>(args)...);
            }catch(InterruptException &ex){
                break;
            }
        }
        return listenerMap.size();
    }

    template<typename ...ArgsType>
    bool emitEventNoCopy(const string &strEvent,ArgsType &&...args){
        lock_guard<recursive_mutex> lck(_mtxListener);
        auto it0 = _mapListener.find(strEvent);
        if (it0 == _mapListener.end()) {
            return false;
        }
        auto &listenerMap = it0->second;
        for(auto &pr : listenerMap){
            typedef function<void(decltype(std::forward<ArgsType>(args))...)> funType;
            funType *obj = (funType *)(pr.second.get());
            try{
                (*obj)(std::forward<ArgsType>(args)...);
            }catch(InterruptException &ex){
                break;
            }
        }
        return listenerMap.size();
    }

    int listenerSize(const string &strEvent){
        lock_guard<recursive_mutex> lck(_mtxListener);
        auto it0 = _mapListener.find(strEvent);
        if (it0 == _mapListener.end()) {
            return 0;
        }
        return it0->second.size();
    }


    template<typename FUN>
    void addListener(void *tag, const string &strEvent, const FUN &fun) {
        typedef typename function_traits<FUN>::stl_function_type funType;
        std::shared_ptr<void> pListener(new funType(fun), [](void *ptr) {
            funType *obj = (funType *)ptr;
            delete obj;
        });
        lock_guard<recursive_mutex> lck(_mtxListener);
        _mapListener[strEvent].emplace(tag,pListener);
    }


    void delListener(void *tag,const string &strEvent){
        lock_guard<recursive_mutex> lck(_mtxListener);
        auto it = _mapListener.find(strEvent);
        if(it == _mapListener.end()){
            return;
        }
        it->second.erase(tag);
        if(it->second.empty()){
            _mapListener.erase(it);
        }
    }
    void delListener(void *tag){
        lock_guard<recursive_mutex> lck(_mtxListener);
        for(auto it = _mapListener.begin();it != _mapListener.end();){
            it->second.erase(tag);
            if(it->second.empty()){
                it = _mapListener.erase(it);
                continue;
            }
            ++it;
        }
    }

    void clearAll(){
        lock_guard<recursive_mutex> lck(_mtxListener);
        _mapListener.clear();
    }
private:
    NoticeCenter(){}
    recursive_mutex _mtxListener;
    unordered_map<string,unordered_multimap<void *,std::shared_ptr<void> > > _mapListener;

};
}


#endif //CV2X_NOTICECENTER_H

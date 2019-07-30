//
// Created by root on 19-7-23.
//

#ifndef CV2X_V2XSETTTING_H
#define CV2X_V2XSETTTING_H
#include "Util/Mini.h"

using namespace toolkit;

namespace v2x {

class V2xSettting :public mINI
{
public:
    V2xSettting(){};
    virtual ~V2xSettting(){};

    bool hasKey(const char *key){
        return this->find(key) != this->end();
    }

    vector<variant> splitedVal(const char *key,const char *delim= ":"){
        vector<variant> ret;
        auto &val = (*this)[key];
        split(val,delim,ret);
        return ret;
    }

private:
    void split(const string& s, const char *delim,vector<variant> &ret){
        int last = 0;
        int index = s.find(delim, last);
        while (index != string::npos) {
            if(index - last > 0){
                ret.push_back(s.substr(last, index - last));
            }
            last = index + strlen(delim);
            index = s.find(delim, last);
        }
        if (s.size() - last > 0) {
            ret.push_back(s.substr(last));
        }
    }
};
}

#endif //CV2X_V2XSETTTING_H

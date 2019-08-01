//
// Created by root on 19-7-23.
//

#ifndef CV2X_V2XSETTTING_H
#define CV2X_V2XSETTTING_H
#include "Util/Mini.h"

using namespace toolkit;
using namespace std;

namespace v2x {

const string path_name = "./conf.ini";


class V2xSettting :public mINI
{
public:

    V2xSettting(){};
    virtual ~V2xSettting(){};

    void load() {
        this->parseFile(path_name);
    }
    void save() {
        this->dumpFile(path_name);
    }

    bool hasKey(const char *key){
        return this->find(key) != this->end();
    }
private:

};

static V2xSettting gInst;
}

#endif //CV2X_V2XSETTTING_H

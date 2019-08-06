//
// Created by root on 19-7-23.
//

#ifndef CV2X_V2XSETTTING_H
#define CV2X_V2XSETTTING_H
#include "Util/Mini.h"

using namespace toolkit;
using namespace std;

namespace v2x {

const string path_name = "../../data/configures.ini";

class V2xSetting : public mINI
{
public:

    static V2xSetting &Instance();

    void load() {
        this->parseFile(path_name);
    }
    void save() {
        this->dumpFile(path_name);
    }

    bool hasKey(const char *key){
        return this->find(key) != this->end();
    }

};

#define SET V2xSetting::Instance()


}

#endif //CV2X_V2XSETTTING_H

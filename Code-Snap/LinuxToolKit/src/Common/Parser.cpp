//
// Created by root on 19-8-30.
//

#include "Parser.h"

namespace toolkit
{

string FindField(const char* buf, const char* start, const char *end ,int bufSize) {
    if(bufSize <=0 ){
        bufSize = strlen(buf);
    }
    const char *msg_start = buf, *msg_end = buf + bufSize;
    int len = 0;
    if (start != NULL) {
        len = strlen(start);
        msg_start = strstr(buf, start);
    }
    if (msg_start == NULL) {
        return "";
    }
    msg_start += len;
    if (end != NULL) {
        msg_end = strstr(msg_start, end);
        if (msg_end == NULL) {
            return "";
        }
    }
    return string(msg_start, msg_end);
}
}
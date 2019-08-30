//
// Created by xuqi on 2019-07-02.
//

#include <thread>
#include <algorithm>
#include "Util.h"
#include "Logger.h"
#include "OnceToken.h"

using namespace std;
namespace toolkit
{

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

string exePath()
{
    char buffer[PATH_MAX * 2 + 1] = {0};
    int n = -1;

    n = readlink("/proc/self/exe", buffer, sizeof(buffer));

    string filePath;
    if (n <= 0) {
        filePath = "./";
    }
    else {
        filePath = buffer;
    }

    return filePath;
}

string exeDir()
{
    auto path = exePath();
    return path.substr(0, path.rfind('/') + 1);
}

string exeName()
{
    auto path = exePath();
    return path.substr(path.rfind('/') + 1);
}

// string转小写
std::string &strToLower(std::string &str)
{
    transform(str.begin(), str.end(), str.begin(), towlower);
    return str;
}
// string转大写
std::string &strToUpper(std::string &str)
{
    transform(str.begin(), str.end(), str.begin(), towupper);
    return str;
}

// string转小写
std::string strToLower(std::string &&str)
{
    transform(str.begin(), str.end(), str.begin(), towlower);
    return std::move(str);
}
// string转大写
std::string strToUpper(std::string &&str)
{
    transform(str.begin(), str.end(), str.begin(), towupper);
    return std::move(str);
}



#define TRIM(s, chars) \
do{ \
    string map(0xFF, '\0'); \
    for (auto &ch : chars) { \
        map[(unsigned char &)ch] = '\1'; \
    } \
    while( s.size() && map.at((unsigned char &)s.back())) s.pop_back(); \
    while( s.size() && map.at((unsigned char &)s.front())) s.erase(0,1); \
    return s; \
}while(0);

vector<string> split(const string& s, const char *delim) {
    vector<string> ret;
    int last = 0;
    int index = s.find(delim, last);
    while (index != string::npos) {
        if (index - last > 0) {
            ret.push_back(s.substr(last, index - last));
        }
        last = index + strlen(delim);
        index = s.find(delim, last);
    }
    if (s.size() - last > 0) {
        ret.push_back(s.substr(last));
    }
    return ret;
}


//去除前后的空格、回车符、制表符
std::string &trim(std::string &s, const string &chars)
{
    TRIM(s, chars);
}

std::string trim(std::string &&s, const string &chars)
{
    TRIM(s, chars);
}

void replace(string &str, const string &old_str, const string &new_str)
{
    if (old_str.empty() || old_str == new_str) {
        return;
    }
    auto pos = str.find(old_str);
    if (pos == string::npos) {
        return;
    }
    str.replace(pos, old_str.size(), new_str);
    replace(str, old_str, new_str);
}

static inline uint64_t getCurrentMicrosecondOrigin()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;

}

static atomic<uint64_t> s_currentMicrosecond(getCurrentMicrosecondOrigin());

static atomic<uint64_t> s_currentMillisecond(getCurrentMicrosecondOrigin() / 1000);

static inline bool initMillisecondThread()
{
    static std::thread s_thread([]()
                                {
                                    DebugL << "Stamp thread started!";
                                    uint64_t now;
                                    while (true) {
                                        now = getCurrentMicrosecondOrigin();
                                        s_currentMicrosecond.store(now, memory_order_release);
                                        s_currentMillisecond.store(now / 1000, memory_order_release);
                                        usleep(500);

                                    }
                                });
    static OnceToken s_token([]()
                             {
                                 s_thread.detach();
                             });
    return true;
}

uint64_t getCurrentMillisecond()
{
    static bool flag = initMillisecondThread();
    return s_currentMillisecond.load(memory_order_acquire);
}

uint64_t getCurrentMicrosecond()
{
    static bool flag = initMillisecondThread();
    return s_currentMicrosecond.load(memory_order_acquire);
}

}
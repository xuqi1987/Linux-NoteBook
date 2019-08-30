
//
// Created by root on 19-8-30.
//

#ifndef CV2X_HTTPCOOKIE_H
#define CV2X_HTTPCOOKIE_H
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <mutex>
using namespace std;

namespace toolkit {
/**
 * http客户端cookie对象
 */
class HttpCookie {
public:
    typedef std::shared_ptr<HttpCookie> Ptr;
    friend class HttpCookieStorage;
    HttpCookie(){}
    ~HttpCookie(){}

    void setPath(const string &path);
    void setHost(const string &host);
    void setExpires(const string &expires,const string &server_date);
    void setKeyVal(const string &key,const string &val);
    operator bool ();

    const string &getKey() const ;
    const string &getVal() const ;
private:
    string _host;
    string _path = "/";
    uint32_t _expire = 0;
    string _key;
    string _val;
};


/**
 * http客户端cookie全局保存器
 */
class HttpCookieStorage{
public:
    ~HttpCookieStorage(){}
    static HttpCookieStorage &Instance();
    void set(const HttpCookie::Ptr &cookie);
    vector<HttpCookie::Ptr> get(const string &host,const string &path);
private:
    HttpCookieStorage(){};
private:
    unordered_map<string/*host*/,map<string/*cookie path*/,map<string/*cookie_key*/,HttpCookie::Ptr> > > _all_cookie;
    mutex _mtx_cookie;
};

}



#endif //CV2X_HTTPCOOKIE_H

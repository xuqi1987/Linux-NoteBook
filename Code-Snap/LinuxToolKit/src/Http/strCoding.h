
//
// Created by root on 19-8-30.
//

#ifndef CV2X_STRCODING_H
#define CV2X_STRCODING_H
#include <iostream>
#include <string>

using namespace std;
namespace toolkit {
class strCoding {
public:
    static string UrlEncode(const string &str); //urlutf8 编码
    static string UrlDecode(const string &str); //urlutf8解码
#if defined(_WIN32)
    static string UTF8ToGB2312(const string &str);//utf_8转为gb2312
	static string GB2312ToUTF8(const string &str); //gb2312 转utf_8
#endif//defined(_WIN32)
private:
    strCoding(void);
    virtual ~strCoding(void);
};
}


#endif //CV2X_STRCODING_H

//
// Created by xuqi on 2019-06-03.
//

#ifndef INC_01_CPPPRIMER_STRING_H
#define INC_01_CPPPRIMER_STRING_H


class String {
public:
    String(const char* str = nullptr);
    String(const String &other); // 拷贝构造函数
    String& operator =(const String &other); // 赋值函数

    virtual ~String();
private:
    char *m_data;

};


#endif //INC_01_CPPPRIMER_STRING_H

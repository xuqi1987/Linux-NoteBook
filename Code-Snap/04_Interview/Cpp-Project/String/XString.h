//
// Created by root on 19-5-31.
//

#ifndef STRING_XSTRING_H
#define STRING_XSTRING_H


class XString {
public:
    XString(const char* str = nullptr);

    XString();

    virtual ~XString();
private:
    char *m_data;
};


#endif //STRING_XSTRING_H

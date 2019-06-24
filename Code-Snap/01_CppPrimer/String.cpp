//
// Created by xuqi on 2019-06-03.
//
#include <assert.h>
#include <string.h>
#include "String.h"

String::String(const char *str)
    : m_data(NULL)
{
    if (nullptr == str)
    {
        m_data = new char[1];
        assert(m_data != nullptr);
        m_data[0] = '\0';
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len+1];
        assert(m_data != nullptr);
        strncpy(m_data,str,len);
        m_data[len] = '\0';
    }
}

String::~String()
{
    delete [] m_data;
    m_data = nullptr;
}
String::String(const String &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];

    strcpy(m_data,other.m_data);

}
String &String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete [] m_data;

    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strncpy(m_data,other.m_data,len);

    m_data[len] = '\0';
    return *this;
}



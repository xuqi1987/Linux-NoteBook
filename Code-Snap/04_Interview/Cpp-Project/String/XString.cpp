//
// Created by root on 19-5-31.
//

#include "XString.h"
#include <assert.h>
#include <string.h>

XString::XString(const char *str)
:m_data(nullptr)
{
    if (nullptr == str)
    {
        m_data = new char[1];
        assert(m_data == nullptr);

        m_data[0] = '\0';
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len + 1];
        assert(m_data == nullptr);

        strncpy(m_data,str,len);
        m_data[len] = '\0';
    }
}


XString::~XString()
{
    delete [] m_data;
    m_data = nullptr;
}
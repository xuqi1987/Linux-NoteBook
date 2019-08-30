//
// Created by root on 19-8-30.
//

#include "strCoding.h"
#include <string.h>


namespace toolkit
{
//////////////////////////通用///////////////////////
void UTF8ToUnicode(wchar_t *pOut, const char *pText)
{
    char *uchar = (char *) pOut;
    uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
    uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);
    return;
}
void UnicodeToUTF8(char *pOut, const wchar_t *pText)
{
    // 注意 WCHAR高低字的顺序,低字节在前，高字节在后
    const char *pchar = (const char *) pText;
    pOut[0] = (0xE0 | ((pchar[1] & 0xF0) >> 4));
    pOut[1] = (0x80 | ((pchar[1] & 0x0F) << 2)) + ((pchar[0] & 0xC0) >> 6);
    pOut[2] = (0x80 | (pchar[0] & 0x3F));
    return;
}

char CharToInt(char ch)
{
    if (ch >= '0' && ch <= '9')return (char) (ch - '0');
    if (ch >= 'a' && ch <= 'f')return (char) (ch - 'a' + 10);
    if (ch >= 'A' && ch <= 'F')return (char) (ch - 'A' + 10);
    return -1;
}
char StrToBin(const char *str)
{
    char tempWord[2];
    char chn;
    tempWord[0] = CharToInt(str[0]); //make the B to 11 -- 00001011
    tempWord[1] = CharToInt(str[1]); //make the 0 to 0 -- 00000000
    chn = (tempWord[0] << 4) | tempWord[1]; //to change the BO to 10110000
    return chn;
}

string strCoding::UrlEncode(const string &str)
{
    string dd;
    size_t len = str.size();
    for (size_t i = 0; i < len; i++) {
        if (isalnum((uint8_t) str[i])) {
            char tempbuff[2];
            sprintf(tempbuff, "%c", str[i]);
            dd.append(tempbuff);
        }
        else if (isspace((uint8_t) str[i])) {
            dd.append("+");
        }
        else {
            char tempbuff[4];
            sprintf(tempbuff, "%%%X%X", (uint8_t) str[i] >> 4, (uint8_t) str[i] % 16);
            dd.append(tempbuff);
        }
    }
    return dd;
}
string strCoding::UrlDecode(const string &str)
{
    string output = "";
    char tmp[2];
    int i = 0, len = str.length();
    while (i < len) {
        if (str[i] == '%') {
            tmp[0] = str[i + 1];
            tmp[1] = str[i + 2];
            output += StrToBin(tmp);
            i = i + 3;
        }
        else if (str[i] == '+') {
            output += ' ';
            i++;
        }
        else {
            output += str[i];
            i++;
        }
    }
    return output;
}

}

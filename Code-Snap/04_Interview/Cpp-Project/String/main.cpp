#include <iostream>
#include <string>
#include <string.h>
using namespace std;

typedef  unsigned char  uint8;

void UTF8SubStr(std::string &src, int max_len)
{
    int last_index = max_len - 1;
    if ((last_index < src.length()) && (max_len > 1))
    {
        unsigned char c = (unsigned char)src[last_index];

        // if utf8 string
        if ((c & 0x80) == 0x80)
        {
            unsigned char t;
            do {
                t = (unsigned char)src[last_index];
                last_index--;
                // find the start index of last utf8 string
            }while(((t & 0xC0 ) == 0xC0) && (last_index > 0));
        }
        src = src.substr(0, last_index);
    }
}

void UTF8StringCutOff(char *pOutput, int iOutLen,const std::string &strInString, int iCutLen)
{
    std::string strTmp(strInString);
    memset(pOutput,0x00,iOutLen);

    if (iCutLen > iOutLen)
         iCutLen = iOutLen;

    if (strTmp.length() >= iCutLen)
    {
        UTF8SubStr(strTmp, iCutLen);
    }

    strncpy(pOutput,strTmp.c_str(),strTmp.length());
    pOutput[strTmp.length()] = '\0';
}

int main() {

    uint8 c[3][10];



    uint8 a[10];
    memset(a,0xff,10);
    std::string b("abcde111111111");
    UTF8StringCutOff((char*)a,10,b,5);
    cout << strlen((char*)&a[1]);


    if (memcmp(c[0],a,10) != 0)
    {
        printf("\naaaa\n");
        memcpy(c[0],a,10);
    }


    for(int i = 0; i < 10; i++)
    {
        printf("%X ",a[i]);
    }

    std::cout <<"\n" <<a << std::endl;

    std::cout << c[0] << std::endl;
//    string a ("hello");
//    std::cout << a[1] << endl;
//    UTF8SubStr(a,1);
//    string tmp =  a.substr(0,2);
//    cout <<tmp[2]<< endl;
//    cout << a[4]<< endl;
    return 0;
}
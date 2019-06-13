#include <iostream>
#include <string.h>
#include <stdio.h>


int main() {
    std::cout << "Hello, World!" << std::endl;
    char a[] = "123456";
    std::string c("123");
    char b[10];
    memset(b,0xFF,sizeof(b));
//    strncpy(b,c.c_str(),sizeof(b));
//
//    int iA = 654321;
//    char aC[4];
//
//    aC[0] = iA & 0xFF;
//    aC[1] = (iA>>8) & 0xFF;
//    aC[2] = (iA>>16) & 0xFF;
//    aC[3] = (iA>>24) & 0xFF;

    strncpy(b,a,strlen(a) + 1);



    //printf("%d",*aC);
    printf("%s",b);
    return 0;
}
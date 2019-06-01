#include <iostream>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
using namespace std;

void recvSignal(int sig) {
    void *buffer[1024];
    int n  = backtrace(buffer,1024);
    char **symbols = backtrace_symbols(buffer,n);
    for (int i = 0; i < n; i ++)
    {
        cout <<symbols[i]<<endl;
    }
    abort();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    signal(SIGSEGV,recvSignal);

    char b[3];
    char a[5] = "1234";
    strcpy(b,a);
    b[4] = 0;
    while(1);
    return 0;
}
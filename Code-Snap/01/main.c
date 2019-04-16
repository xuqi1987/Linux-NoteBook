#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

    int ret;
    unsigned char buff = 0;
    FILE *fp = NULL;

    while (1) {

        fp = fopen("/dev/cy_diag","r");

        if (NULL == fp)
        {
            printf("Open Failed\n");
            return 0 ;
        }

        ret = fread(&buff,sizeof(unsigned char),1,fp);

        fclose(fp);

        printf("%x\n",buff);
        sleep(1);
    }
    
    return 0;
}
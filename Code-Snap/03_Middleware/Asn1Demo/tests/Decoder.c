
//
// Created by root on 19-7-17.
//
#include <stdio.h>
#include <sys/types.h>
#include "Rectangle.h"
#include "../src/Rectangle.h"


int main()
{
    Rectangle_t *rectangle = 0;


    char buf[1024];
    size_t size;

    rectangle = calloc(1, sizeof(Rectangle_t));

    const char *filename = "./rect.txt";
    FILE *fp = fopen(filename,"rb");

    size = fread(buf,1,sizeof(buf),fp);
    fclose(fp);

    ber_decode(0, &asn_DEF_Rectangle,(void **)& rectangle,buf,size);

    xer_fprint(stdout, &asn_DEF_Rectangle,rectangle);

    return 0;
}

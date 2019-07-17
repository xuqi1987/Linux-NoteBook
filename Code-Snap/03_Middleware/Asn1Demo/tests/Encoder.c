//
// Created by root on 19-7-17.
//
#include <stdio.h>
#include <sys/types.h>
#include "Rectangle.h"

static int write_out(const void*buffer, size_t size,void *app_key) {
    FILE *out_fp = app_key;
    size_t wrote = fwrite(buffer,1,size,out_fp);
    return (wrote == size) ? 0 : -1;
}

int main()
{
    Rectangle_t *rectangle;
    asn_enc_rval_t ec;

    rectangle = calloc(1, sizeof(Rectangle_t));

    rectangle->height = 42;
    rectangle->width = 23;

   const char *filename = "./rect.txt";
   FILE *fp = fopen(filename,"wb");

   ec = der_encode(&asn_DEF_Rectangle,rectangle,write_out, fp);
   fclose(fp);

   xer_fprint(stdout, &asn_DEF_Rectangle,rectangle);

    return 0;
}

//
// Created by root on 19-7-17.
//
#include <sys/types.h>
#include <stdio.h>
#include "BasicSafetyMessage.h"

static int write_out(const void *buffer, size_t size, void *app_key)
{
    FILE *out_fp = (FILE *) app_key;
    size_t wrote = fwrite(buffer, 1, size, out_fp);
    return (wrote == size) ? 0 : -1;
}

int main()
{
    BasicSafetyMessage_t *BSM = new BasicSafetyMessage_t();
    BSM->msgCnt = (MsgCount_t) 100;

    const char *filename = "./rect.txt";
    FILE *fp = fopen(filename, "wb");

    der_encode(&asn_DEF_BasicSafetyMessage, BSM, write_out, fp);

    fclose(fp);

    xer_fprint(stdout, &asn_DEF_BasicSafetyMessage, BSM);

    delete BSM;
    return 0;
}
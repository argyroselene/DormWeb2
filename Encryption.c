#include<stdio.h>
#include<stdlib.h>
#include<string.h>


unsigned long
    encryption(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

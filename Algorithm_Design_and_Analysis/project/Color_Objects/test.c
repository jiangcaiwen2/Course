#include<stdio.h>
#include<stdlib.h>
#define ALL 6291456
#define A1 16
#define A2 256
#define A3 4096
#define A4 65536
#define A5 1048576

int *t;

int main()
{
    int tmp;
    t = (int*)malloc(sizeof(int)*ALL);
    // t[24]=9;
    // printf("%d", t[24]);

    int a,b,c,d,e,f;
    a=3;
    b=4;
    c=12;
    d=15;
    e=0;
    f=5;
    printf("%d\n", a+b*A1+c*A2+d*A3+e*A4+f*A5);
    printf("%d", a + (b<<4) + (c<<8) + (d<<12) + (e<<16) + (f<<20));
    // printf("%d", f<<20);

    return 0;
}
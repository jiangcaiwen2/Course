#include<stdio.h>
#include<stdlib.h>
#define ALL 6291456
#define MAXNUM 1000000007

long long *t;
long long solve(long long a, long long b, long long c, long long d, long long e, long long f);

long long solve(long long a, long long b, long long c, long long d, long long e, long long f)
{
    long long num = 0;
    long long idx = a + (b<<4) + (c<<8) + (d<<12) + (e<<16) + (f<<20);
    long long tmpa = 0;
    long long tmpb = 0;
    long long tmpc = 0;
    long long tmpd = 0;
    if(t[idx] > -1)
        return t[idx];
    // num = t[idx]+t[idx]+t[idx]+t[idx]+t[idx];
    switch (f)
    {
    case 1:
        tmpa++;
        break;
    case 2:
        tmpb++;
        break;
    case 3:
        tmpc++;
        break;
    case 4:
        tmpd++;
        break;
    default:
        break;
    }
    if(a>=1)
    {
        num += a*solve(a-1+tmpa,b+tmpb,c+tmpc,d+tmpd,e,0);
        if(num>MAXNUM)
            num = num%MAXNUM;
    }
        
    if(b>=1)
    {
        num += b*solve(a+tmpa,b-1+tmpb,c+tmpc,d+tmpd,e,1);
        if(num>MAXNUM)
            num = num%MAXNUM;
    }
        
    if(c>=1)
    {
        num += c*solve(a+tmpa,b+tmpb,c-1+tmpc,d+tmpd,e,2);
        if(num>MAXNUM)
            num = num%MAXNUM;
    }
        
    if(d>=1)
    {
        num += d*solve(a+tmpa,b+tmpb,c+tmpc,d-1+tmpd,e,3);
        if(num>MAXNUM)
            num = num%MAXNUM;
    }
        
    if(e>=1)
    {
        num += e*solve(a+tmpa,b+tmpb,c+tmpc,d+tmpd,e-1,4);
        if(num>MAXNUM)
            num = num%MAXNUM;
    }
        
    t[idx] = num;
    // printf("\n---\n");
    // printf("%d %d", idx, num);

    return num;
}

int main()
{
    freopen("test.in", "r", stdin);
    t = (long long*)malloc(sizeof(long long)*ALL);
    for(int i=0; i<ALL; i++)
    {
        t[i] = -1;
    }
    t[1] = 1;
    int k;
    long long num;
    int tmp;
    scanf("%d", &k);
    long long color[5];
    for(int i=0;i<5;i++)
    {
        color[i]=0;
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d", &tmp);
        color[tmp-1]++;
    }
    num = solve(color[0], color[1], color[2], color[3], color[4], 0);
    printf("%ld", num);

    return 0;
}
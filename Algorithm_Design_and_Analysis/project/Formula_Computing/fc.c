#include<stdio.h>
#include<stdlib.h>
typedef long long LL;
#define P 1004535809
#define N 262144
#define G 3

int main()
{
    // char *buf1 = malloc(1 << 20);
    // char *buf2 = malloc(1 << 20);

    // setvbuf(stdin, buf1, _IOFBF, 1 << 20);
    // setvbuf(stdout, buf2, _IOFBF, 1 << 20);
    freopen("test2.in", "r", stdin);
    FILE *fp =  freopen("test.out", "w", stdout);

    int n;
    LL *a, *b, *c;
    scanf("%d", &n);
    a = (LL*)malloc(N, sizeof(LL));
    b = (LL*)malloc(N, sizeof(LL));
    c = (LL*)calloc(N, sizeof(LL));
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", a+i, b+i);
    }
    // 读取完毕


    // 输出部分
    for(int i=0; i<n; i++)
    {
        // c[i] = 0;
        // for(int j=i; j<n; j++)
        // {
        //     c[i] += a[j]*b[j-i];
        // }
        printf("%d\n", c[i]);
    }

    fclose(fp);
    
    return 0;
}
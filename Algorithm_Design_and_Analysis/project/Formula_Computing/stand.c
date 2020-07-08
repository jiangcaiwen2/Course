#include<stdio.h>
#include<stdlib.h>

int main()
{
    // char *buf1 = malloc(1 << 20);
    // char *buf2 = malloc(1 << 20);

    // setvbuf(stdin, buf1, _IOFBF, 1 << 20);
    // setvbuf(stdout, buf2, _IOFBF, 1 << 20);
    freopen("test2.in", "r", stdin);
    FILE *fp =  freopen("test.out", "w", stdout);

    int n, *a, *b, *c;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int)*n);
    c = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", a+i, b+i);
    }
    // 读取完毕


    // 输出部分
    for(int i=0; i<n; i++)
    {
        c[i] = 0;
        for(int j=i; j<n; j++)
        {
            c[i] += a[j]*b[j-i];
        }
        printf("%d\n", c[i]);
    }

    fclose(fp);
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE * fp = freopen("test2.in", "w", stdout);
    int n;
    // int *a, *b, *c;
    n = 100000;
    // a = (int*)malloc(sizeof(int)*n);
    // b = (int*)malloc(sizeof(int)*n);

    // 输出部分
    printf("%d\n", n);
    for(int i=0; i<n; i++)
    {
        printf("%d %d\n", rand()%100, rand()%100);
    }
    fclose(fp);
    
    return 0;
}
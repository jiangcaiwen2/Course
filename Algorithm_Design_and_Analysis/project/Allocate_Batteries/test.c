#include<stdio.h>
#include<stdlib.h>
int cmp(const void *, const void *);

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int a[] = {1,2,5,8,12,3,0,9};
    qsort(a, 8, sizeof(int), cmp);
    for(int i=0; i<8; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
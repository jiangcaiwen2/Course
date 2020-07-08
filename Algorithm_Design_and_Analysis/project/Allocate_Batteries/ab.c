#include<stdio.h>
#include<stdlib.h>
int cmp(const void *, const void *);

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main()
{
    freopen("test.in", "r", stdin);
    int n, k;
    int *a, *b;
    scanf("%d %d", &n, &k);
    int N=2*n*k;
    a = (int *)malloc(sizeof(int)*N);
    b = (int *)malloc(sizeof(int)*(N-1));
    for(int i=0; i<N; i++)
    {
        scanf("%d ", a+i);
    }
    // printf("read over\n");
    // 输入完毕
    qsort(a, N, sizeof(int), cmp);
    int maxb, minb;
    maxb = 0;
    for(int i=0; i<N-1; i++)
    {
        b[i] = a[i+1]-a[i];
        if(maxb<b[i])
            maxb=b[i];
    }
    minb = b[0];
    // 预处理结束

    int mid, count, round;
    int k2 = 2*k;
    int flag;
    int in, out, out_tmp;
    int j=0;
    while(1)
    {
        mid = (maxb+minb)/2;
        // count = 0;
        in = 0;
        out = 0;
        round = 0;
        flag = 0;
        // for(int i=0; i<N-1; i++)
        int i = 0;
        while(round <n)
        {
            
            out_tmp = (in>out) ? in : out;
            if(b[i] <= mid)   
            {
                in = out+1;
                // count++;
            }else
            {
                in = out_tmp;
            }
            out = out_tmp;
            count = (in>out)? in:out;
            // printf("%d: in and out %d %d\n", i, in, out);
            if(i%(k2) == 0)
            {
                round++;
                if(count < round) 
                {
                    minb = mid+1;
                    flag = 1;
                    // printf("%d %d\n", count, round);
                    break;
                }
            }
            i++;
        }
        // printf("%d %d %d %d \n", j, minb, mid, maxb);
        j++;
        //  下面已完成
        if(minb >= maxb)
        {
            mid = maxb;
            break;
        }
        if( 0 == flag)
        {
            maxb = mid;
        }
    }

    printf("%d", mid);

    return 0;
}
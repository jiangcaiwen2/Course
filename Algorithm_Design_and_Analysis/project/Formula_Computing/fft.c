#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct com ctype;
ctype mul(ctype c1, ctype c2);
ctype add(ctype c1, ctype c2);
ctype sub(ctype c1, ctype c2);
int rev(int k, int lgn);
void fft(ctype* a, ctype* A, int n, int lgn, int sign);

int rev(int k, int lgn)
{
    int ans = 0;
    int tmp = k;
    for (int i=lgn-1; i>=0; i--)
    {
        ans = ((tmp & 1) << i) | ans;
        tmp = tmp >> 1;
    }
    return ans;
}

struct com
{
    double r;
    double i;
};

ctype add(ctype c1, ctype c2)
{
    ctype ans;
    ans.r = c1.r+c2.r;
    ans.i = c1.i+c2.i;
    return ans;
}

ctype sub(ctype c1, ctype c2)
{
    ctype ans;
    ans.r = c1.r-c2.r;
    ans.i = c1.i-c2.i;
    return ans;
}

ctype mul(ctype c1, ctype c2)
{
    ctype ans;
    ans.r = c1.r*c2.r - c1.i*c2.i;
    ans.i = c1.r*c2.i + c2.r*c1.i;
    return ans;
}

void fft(ctype* a, ctype* A, int n, int lgn, int sign)
{
    int idx;
    double pi = acos(-1.0);
    for(int k=0; k<n; k++)
    {
        idx = rev(k, lgn);
        A[idx].r = a[k].r;
        A[idx].i = a[k].i;
    }

    int m=1;
    int m2;

    ctype omega;
    ctype omega_m;
    ctype tmp;
    ctype tmp_u;
    double zelta;
    for(int s=1; s<= lgn; s++)
    {
        m2 = m;
        m = m << 1;
        // printf("%d:%d ",s, m);
        // omega
        zelta = 2*pi/m;
        omega_m.r = cos(zelta); 
        omega_m.i = sin(sign*zelta);
        for(int k=0; k<n; k+=m)
        {
            omega.r = 1;
            omega.i = 0;
            for(int j=0; j<m2; j++)
            {
                tmp = mul(omega, A[k+j+m2]);
                tmp_u = A[k+j];
                A[k+j] = add(tmp_u, tmp);
                A[k+j+m2] = sub(tmp_u, tmp);
                omega = mul(omega, omega_m);
            }
        }
    }

}

int main()
{
    // freopen("testdata.in", "r", stdin);
    freopen("test2.in", "r", stdin);
    FILE * fp = freopen("fft.out", "w", stdout);
    int n, N, lgn;
    int tmp1, tmp2;
    ctype *a, *b, *c;
    ctype *a2, *b2, *c2;
    scanf("%d", &n);
    lgn = ceil(log2(2*n));
    N = round(pow(2, lgn));
    a = (ctype* )calloc(N, sizeof(ctype));
    b = (ctype* )calloc(N, sizeof(ctype));
    c = (ctype* )calloc(N, sizeof(ctype));
    a2 = (ctype* )calloc(N, sizeof(ctype));
    b2 = (ctype* )calloc(N, sizeof(ctype));
    c2 = (ctype* )calloc(N, sizeof(ctype));

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        a[i].r = (double)tmp1;
        b[n-1-i].r = (double)tmp2;
    }

    fft(a, a2, N, lgn, -1);
    fft(b, b2, N, lgn, -1);
    // printf("N:%d lgn:%d\n", N, lgn);
    for(int i=0; i<N; i++)
    {
        c2[i]=mul(a2[i], b2[i]);
    }
    fft(c2, c, N, lgn, 1);
    for(int i=0; i<n; i++)
    {
        printf("%d\n", (int)round(c[i+n-1].r/N) );
    }
  
    // fclose(fp);

    return 0;
}
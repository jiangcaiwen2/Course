#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926
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
    //bit
    for(int k=0; k<n; k++)
    {
        idx = rev(k, lgn);
        A[idx].r = a[k].r;
        A[idx].i = a[k].i;
        // printf("%d ", idx);
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
                // printf("s:%d k:%d j:%d m2:%d Ar:%f Ai:%f Ar:%f Ai:%f\n",s,k,j, m2,A[k+j].r, A[k+j].i, A[k+j+m2].r, A[k+j+m2].i);
            }
        }
    }

}

int main()
{
    int n=8;
    double a[] = {2,3,4,7 ,10,3,2,6};
    ctype A[8];
    ctype B[8];
    ctype a2[8];
    for(int i=0; i<n; i++)
    {
        a2[i].r = a[i];
        a2[i].i = 0;
    }
    fft(a2, A, n, 3, -1);
    fft(A, B, n, 3, 1);
    // for(int i=0; i<n; i++)
    // {
    //     printf("%f %f\n", B[i].r / n, B[i].i / n);
    //     // printf("%f %f\n", A[i].r , A[i].i );
    // }

    return 0;
}
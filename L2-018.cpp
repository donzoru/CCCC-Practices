#include<bits/stdc++.h>
using namespace std;
#define M 100100
int n,m;
double a[M],b[M],c[M];
int x,y;
#define eps 1e-8
int main(){
    x = y = -1;
    scanf("%d",&n);
    for(int i=0,j;i<n;++i){
        scanf("%d",&j); x = max(x,j);
        scanf("%lf",a+j);
    }
    scanf("%d",&m);
    for(int i=0,j;i<m;++i){
        scanf("%d",&j); y = max(y,j);
        scanf("%lf",b+j);
    }
    for(int i=x;i>=y;--i){
        double t = a[i]/b[y];
        c[i-y] = t;
        for(int j=y;j>=0;--j)
            a[i-y+j] -= t*b[j];
    }
    n = m = 0;
    for(int i=0;i<=y;++i) {
        if(fabs(a[i]) < eps)  continue;
        fabs(a[i]) < 0.05 ? a[i] = 0.0 : ++n;
    }
    for(int i=0;i<=x-y;++i) {
        if(fabs(c[i]) < eps)  continue;
        fabs(c[i]) < 0.05 ? c[i] = 0.0 : ++m;
    }
    printf("%d",m);
    if(m==0){
        puts(" 0 0.0");
    }else {
        for(int i=x-y;i>=0;--i) if(fabs(c[i]) >= eps) printf(" %d %.1f",i,c[i]);
        putchar('\n');
    }
    printf("%d",n);
    if(n==0){
        puts(" 0 0.0");
    }else {
        for(int i=y-1;i>=0;--i) if(fabs(a[i]) >= eps) printf(" %d %.1f",i,a[i]);
        putchar('\n');
    }
    return 0;
}

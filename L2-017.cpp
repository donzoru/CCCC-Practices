#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
int a[M],n;
int b,c,d;
int main(){
    scanf("%d",&n);
    b=d=0;
    for(int i=0;i<n;++i) scanf("%d",a+i),d+=a[i];
    sort(a,a+n);
    for(int i=0;i<n/2;++i) b+=a[i];
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n",n-n/2,n/2,d-b-b);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define M 10010
bool ok[M];
int p[M];
int n,k,a,b;
int getp(int x){
    return p[x]==x?p[x]:p[x]=getp(p[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<M;++i) p[i]=i;
    for(int i=0;i<n;++i){
        scanf("%d%d",&k,&a);
        ok[a]=true;
        for(int j=1;j<k;++j){
            scanf("%d",&b);
            ok[b]=true;
            a=getp(a); b=getp(b);
            if(a==b) continue;
            p[b]=a;
        }
    }
    int sum=0,tot=0;
    for(int i=0;i<M;++i){
        if(ok[i]){
            ++tot;
            if(p[i]==i) ++sum;
        }
    }
    printf("%d %d\n",tot,sum);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(getp(a)==getp(b)) puts("Y");
        else puts("N");
    }
    return 0;
}

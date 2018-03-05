#include<bits/stdc++.h>
using namespace std;
#define M 2010
int p[M],s[M],n,k,h;
int ans[M],top;
int getp(int x){
    return p[x]==x?p[x]:p[x]=getp(p[x]);
}
void merg(int a,int b){
    a=getp(a), b=getp(b);
    if(a==b) return;
    p[b]=a;
    s[a]+=s[b];
    s[b]=0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<M;++i) p[i]=i;
    for(int i=1;i<=n;++i){
        s[1000+i]=1;
        scanf("%d",&k); getchar();
        while(k--){
            scanf("%d",&h);
            merg(1000+i,h);
        }
    }
    for(int i=1001;i<M;++i)
        if(s[i]) ans[top++]=s[i];
    printf("%d\n",top);
    sort(ans,ans+top,greater<int>() );
    for(int i=0;i<top;++i) printf("%d%c",ans[i],i==top-1?'\n':' ');
    return 0;
}
/**
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

*/


#include<bits/stdc++.h>
using namespace std;
#define M 1050010
int a[M],out[M],n,flo;
void ins(int t){
    int p=1,f=1;
    while(a[p]!=-1){
        if(t>a[p]) p=p<<1;
        else p=p<<1|1;
        ++f;
    }
    a[p]=t; flo=max(flo,f);
}
void bfs(){
    int c=0;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int t=q.front();q.pop();
        out[c++]=a[t];
        if(a[t<<1]>0) q.push(t<<1);
        if(a[t<<1|1]>0) q.push(t<<1|1);
    }
}
bool ok(){
    int s=1<<(flo-1),too=0;
    int t=1<<flo;
    for(int i=1;i<s;++i) if(a[i]==-1) return false;
    for(int i=s;i<t;++i) if(a[i]!=-1) too=max(too,i);
    for(int i=s;i<t;++i) if(a[i]==-1 && i<too) return false;
    return true;
}
int main(){
    scanf("%d",&n);
    memset(a,-1,sizeof(a)); flo=1;
    for(int t,i=0;i<n;++i){
        scanf("%d",&t);
        ins(t);
    }
    bfs();
    for(int i=0;i<n;++i) printf("%d%c",out[i],i==n-1?'\n':' ');
    puts(ok()?"YES":"NO");
    return 0;
}

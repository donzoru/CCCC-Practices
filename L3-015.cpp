#include<bits/stdc++.h>
using namespace std;
const int M = 22;
int ans[22];
char g[M][M];
bool vis[M],ok[M][1<<M];
int n;
void dfs(int p,int s,int st){
    if(n==-1) return;
    if(s==n){
        if(g[p][1]!='W' && g[1][p]!='L') return;
        for(int i=0;i<n;++i) cout<<ans[i]<<(i==n-1?'\n':' ');
        n=-1;
        return;
    }
    for(int i=1,j=1,k;i<=n;++i){
        j <<= 1;
        k = st|j;
        if(vis[i] || (g[p][i]!='W' && g[i][p]!='L') || ok[i][k])  continue;
        ok[i][k]=true;
        ans[s]=i;
        vis[i]=true;
        dfs(i,s+1,k);
        vis[i]=false;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>g[i]+1;
    vis[1]=true; ans[0]=1;
    dfs(1,1,1);
    if(n!=-1) cout<<"No Solution"<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int M = 503;
bool vis[M];
bool mapp[M][M];
int n,m;
void dfs(int k)
{
    vis[k]=1;
    for(int i=0;i<n;++i){
        if(mapp[k][i] && !vis[i])
            dfs(i);
    }
}
int coun()
{
    int res=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;++i)
        if(vis[i]==0) ++res,dfs(i);
    return res;
}
int main()
{
    cin>>n>>m;

    memset(mapp,0,sizeof(mapp));
    int a,b;
    while(m--){
        cin>>a>>b;
        mapp[a][b]=mapp[b][a]=1;
    }
    a=coun();
    cin>>m;
    for(int j=0;j<m;++j){
        cin>>b;
        for(int i=0;i<n;++i)
            mapp[b][i]=mapp[i][b]=0;
        int t=coun();
        if(t>a+1)
            printf("Red Alert: City %d is lost!\n",b);
        else printf("City %d is lost.\n",b);
        a=t;
        if(j==n-1) puts("Game Over.");
    }
    return 0;
}

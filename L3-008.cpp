#include<bits/stdc++.h>
using namespace std;
#define M 10010
#define pp pair<int,int>
#define mp make_pair
vector<int> g[M];
bool vis[M];
int n,m,k;
struct cmp{
    bool operator ()(const pp&a,const pp&b)const{
        return a.first > b.first;
    }
};
int bfs(int s){
    priority_queue<pp,vector<pp>,cmp> q;
    memset(vis,0,sizeof(vis));
    q.push(mp(0,s)); vis[s]=true;
    int mx = -1,ans = INT_MAX;
    for(int u,v,s;!q.empty();){
        pp t = q.top(); q.pop();
        s = t.first, u=t.second;
        if(s >= mx){
            if(s==mx) ans=min(ans,u);
            else ans=u;
            mx = s;
        }
        for(int i=0;i<g[u].size();++i){
            v = g[u][i];
            if(vis[v]) continue;
            vis[v]=true;
            q.push(mp(s+1,v));
        }
    }
    return ans==s?0:ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int a,b;m--;){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int a;k--;){
        scanf("%d",&a);
        printf("%d\n",bfs(a));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define M 1010
vector<int> g[M];
set<int> s;
int c[M],v,e,k;
bool vis[M],flag;
void dfs(int v){
    if(vis[v] || !flag) return;
    vis[v]=true;
    for(auto u:g[v]){
        if(c[u]==c[v]) {
            flag=false;
            return;
        }
        dfs(u);
    }
}
int main(){
    scanf("%d%d%d",&v,&e,&k);
    for(int a,b;e--;){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d",&e);
    for(flag=true;e--;flag=true){
        s.clear();
        for(int i=1;i<=v;++i) {
            scanf("%d",c+i);
            s.insert(c[i]);
        }
        if(s.size()!=k){
            puts("No");
            continue;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=v;++i){
            if(vis[i]) continue;
            dfs(i);
            if(!flag) break;
        }
        puts(flag?"Yes":"No");
    }
    return 0;
}

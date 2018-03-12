#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
vector<int> g[M];
int h[M][2];
bool vis[M];
int n,a,b,c;
set<int> ss;
struct info{
    int code;
    double num,tot,sqr;
    bool operator < (const info & x)const {
        if(sqr * x.num == x.sqr * num) return code < x.code;
        return sqr * x.num > x.sqr * num;
    }
};
info ifo[M];
void dfs(int u){
    vis[u]=true;
    ifo[c].num = ifo[c].num + 1;
    ifo[c].tot += h[u][1];
    ifo[c].sqr += h[u][0];
    for(int i=0;i<g[u].size();++i)
        if(!vis[g[u][i]]) dfs(g[u][i]);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        ss.insert(a),ss.insert(b),ss.insert(c);
        if(b!=-1) g[a].push_back(b),g[b].push_back(a);
        if(c!=-1) g[a].push_back(c),g[c].push_back(a);
        scanf("%d",&c);
        while(c--){
            scanf("%d",&b);
            ss.insert(b);
            if(b!=-1) g[a].push_back(b),g[b].push_back(a);
        }
        scanf("%d %d",&b,&c);
        h[a][0] += c; h[a][1] += b;
    } c = 0; ss.erase(-1);
    for(auto i:ss){
        if(vis[i]) continue;
        ifo[c].code = i;
        ifo[c].num = ifo[c].sqr = ifo[c].tot = 0.0;
        dfs(i); ++c;
    }
    sort(ifo,ifo+c);
    printf("%d\n",c);
    for(int i=0;i<c;++i){
        printf("%04d %.0f %.3f %.3f\n",ifo[i].code,ifo[i].num,
                                     ifo[i].tot/ifo[i].num,
                                     ifo[i].sqr/ifo[i].num);
    }
    return 0;
}

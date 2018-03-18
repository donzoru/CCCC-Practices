#include<bits/stdc++.h>
using namespace std;
const int M = 210;
const int INF = 0x3f3f3f3f;
map<string,int> mp;
map<int,string> rm;
int n,k,c;
string st,ed;
int em[M],p[M],cnt[M];
int dis[3][M];
bool vis[M];
int g[M][M];
void dij(){
    for(int i=0;i<n;++i) dis[0][i]=INF,dis[1][i]=dis[2][i]=0;
    memset(vis,0,sizeof(vis));
    memset(p,-1,sizeof(p));
    dis[1][0]=cnt[0]=1;
    dis[0][0]=0;
    for(int k,mini;mini=INF;){
        for(int i=0;i<n;++i)
            if(!vis[i] && mini > dis[0][i])
                k=i,mini=dis[0][i];
        if(mini==INF) break;
        vis[k]=true;
        for(int i=0;i<n;++i){
            if(vis[i] || g[k][i]==INF) continue;
            if(dis[0][i] > dis[0][k] + g[k][i]){
                dis[0][i] = dis[0][k] + g[k][i];
                dis[1][i] = dis[1][k] + 1;
                dis[2][i] = dis[2][k] + em[i];
                p[i] = k;
                cnt[i] = cnt[k];
            }else if(dis[0][i] == dis[0][k] + g[k][i] &&
                     dis[1][i] < dis[1][k] + 1){
                dis[1][i] = dis[1][k] + 1;
                dis[2][i] = dis[2][k] + em[i];
                p[i] = k;
                cnt[i] += cnt[k];
            }else if(dis[0][i] == dis[0][k] + g[k][i] &&
                     dis[1][i] == dis[1][k] + 1 &&
                     dis[2][i] < dis[2][k] + em[i]){
                dis[2][i] = dis[2][k] + em[i];
                p[i] = k;
                cnt[i] += cnt[k];
            }
        }
    }
    dis[1][n-1]=-1;
    for(int i=p[n-1],j=n-1;i!=-1;j=i,i=p[i]) dis[1][i]=j;
    cout<<st;
    for(int i=dis[1][0];i!=-1;i=dis[1][i]) cout<<"->"<<rm[i];
    cout<<endl<<cnt[n-1]<<' '<<dis[0][n-1]<<' '<<dis[2][n-1]<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>st>>ed;
    mp[st] = 0; rm[0]=st;
    mp[ed] = n-1; rm[n-1]=ed;
    c=1;
    for(int i=1,j;i<n;++i){
        string t;
        cin>>t>>j;
        if(t == ed) { em[mp[t]]=j; continue; }
        mp[t]=c;
        rm[c]=t;
        em[c++] = j;
    }
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<M;++i) g[i][i]=0;
    for(string s,t;k--;){
        int w;
        cin>>s>>t>>w;
        int a=mp[s],b=mp[t];
        g[a][b]=g[b][a]=w;
    }
    dij();
    return 0;
}

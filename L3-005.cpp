#include<bits/stdc++.h>
using namespace std;
#define M 1100
const int INF = 0x3f3f3f3f;
int n,m,k,d;
int dist[M];
bool vis[M];
vector<int> g[M],w[M];
int dis,id,tot;
#define pp pair<int,int>
struct cmp{
public:
    bool operator ()(const pp &a,const pp&b)const {
        return a.first > b.first;
    }
};
void dij(int s){
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    priority_queue<pp,vector<pp>,cmp>q;
    q.push(make_pair(0,s));
    dist[s]=0;
    for(int u,v,c;!q.empty();){
        pp t = q.top(); q.pop();
        u = t.second;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<g[u].size();++i){
            v=g[u][i]; c=w[u][i]; //cout<<v<<' ';
            if(!vis[v] && dist[v] > dist[u]+c){
                dist[v]=dist[u]+c;
                q.push(make_pair(dist[v],v));
            }
        }
    }
    int mini=INF, sum=0;
    for(int i=1;i<=n;++i){
        if(dist[i] > d) return;
        sum += dist[i];
        mini = min(mini,dist[i]);
    }
    if(mini==dis && tot==sum && s < id) id = s;
    if(mini==dis && tot > sum) tot = sum,id = s;
    if(mini > dis) dis = mini,tot = sum,id = s;
}
int main(){
    char s[25];
    scanf("%d%d%d%d",&n,&m,&k,&d); getchar();
    for(int a,b,c,t,i=0;i<k;++i){
        cin.getline(s,25);
        t = 0;
        for(int j=0;s[j];++j) t+=s[j]=='G';
        if(t==0){
            sscanf(s,"%d %d %d",&a,&b,&c);
        }else if(t==1){
            if(s[0]=='G') sscanf(s,"G%d %d %d",&a,&b,&c),a+=n;
            else sscanf(s,"%d G%d %d",&a,&b,&c),b+=n;
        }else if(t==2){
            sscanf(s,"G%d G%d %d",&a,&b,&c);
            a+=n, b+=n;
        }
        g[a].push_back(b); w[a].push_back(c);
        g[b].push_back(a); w[b].push_back(c);
    }
    dis = tot = -1;
    id = INF;
    for(int i=n+1;i<=n+m;++i) dij(i);
    if(id == INF) puts("No Solution");
    else {
        double a= dis,b = tot /(double)n;
        printf("G%d\n%.1f %.1f\n",id-n,a,b);
    }
    return 0;
}

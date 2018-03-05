#include<bits/stdc++.h>
using namespace std;
#define M 510
#define pp pair<int,int>
#define INF 0x3f3f3f3f
#define mp make_pair
int w[M][M],t[M][M];
int aa[M],bb[M],ta,tb;
int p[M],dis[M],num[M];
bool vis[M];
int n,m,s,e,cTime,cDist;
struct cmp{
    bool operator ()(const pp&a,const pp&b)const {
        return a.first > b.first;
    }
};
void dij(int *path,int &top,int &cost,bool flag){
    for(int i=0;i<n;++i) p[i]=-1,num[i]=dis[i]=INF,vis[i]=false;
    priority_queue<pp,vector<pp>,cmp> q;
    q.push(mp(0,s));
    dis[s]=0;
    auto g = (flag?t:w);
    if(flag) num[s]=0;
    else num[s]=1;
    for(int a,b,c;!q.empty();){
        pp tem = q.top(); q.pop();
        a = tem.second;
        if(vis[a]) continue;
        vis[a]=true;
        for(int i=0;i<n;++i){
            if(i==a) continue; b=i;
            c=g[a][b];
            if(vis[i]) continue;
            if(dis[b]>dis[a]+c){
                dis[b]=dis[a]+c; p[b]=a;
                if(flag) num[b]=num[a]+w[a][b];
                else num[b]=num[a]+1;
                q.push(mp(dis[b],b));
            }else if(dis[b]==dis[a]+c){
                if(flag){
                    if(num[b] > num[a]+w[a][b]){
                        num[b] = num[a]+w[a][b];
                        p[b]=a;
                        q.push(mp(dis[b],b));
                    }
                }else {
                    if(num[b] > num[a]+1){
                        num[b] = num[a]+1;
                        p[b]=a;
                        q.push(mp(dis[b],b));
                    }
                }
            }
        }
    }
    top = 0;
    for(int i=e;i!=-1;i=p[i]) path[top++]=i;
    cost = dis[e];
}
bool ok(int *a,int *b){
    for(int i=0;i<M;++i)
        if(a[i]!=b[i]) return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int a,b,c,d,e;m--;){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        t[a][b]=e; w[a][b]=d;
        if(c==0) t[b][a]=e,w[b][a]=d;
    }
    scanf("%d%d",&s,&e);
    dij(aa,ta,cTime,true);
    dij(bb,tb,cDist,false);
    if(ok(aa,bb)){
        printf("Time = %d: %d ",cTime,aa[ta-1]);
        for(int i=ta-2;i>=0;--i) printf(" => %d",aa[i]); puts("");
        printf("Distance = %d: %d ",cDist,bb[tb-1]);
        for(int i=tb-2;i>=0;--i) printf(" => %d",bb[i]); puts("");
    }else{
        printf("Time = %d; Distance = %d: %d ",cTime,cDist,aa[ta-1]);
        for(int i=ta-2;i>=0;--i) printf(" => %d",aa[i]); puts("");
    }
    return 0;
}

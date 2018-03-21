#include<bits/stdc++.h>
using namespace std;
#define M 510
#define pp pair<int,int>
#define INF 0x3f3f3f3f
#define mp make_pair
vector<pp> w[M],t[M];
int aa[M],bb[M],ta,tb;
int p[M],dis[M],num[M];
bool vis[M];
int n,m,s,e,cTime,cDist;
struct cmp{
    bool operator ()(const pp&a,const pp&b)const {
        return a.first > b.first;
    }
};
void dij1(){
    for(int i=0;i<n;++i) p[i]=-1,num[i]=dis[i]=INF,vis[i]=false;
    priority_queue<pp,vector<pp>,cmp> q;
    q.push(mp(0,s));
    dis[s]=num[s]=0;
    for(int a,b,c;!q.empty();){
        pp tem = q.top(); q.pop();
        a = tem.second;
        if(vis[a]) continue;
        vis[a]=true;
        for(int i=0;i<t[a].size();++i){
            b=t[a][i].first; c=t[a][i].second;
            if(vis[b]) continue;
            if(dis[b]>dis[a]+c){
                dis[b]=dis[a]+c;
                p[b]=a;
                num[b]=num[a]+w[a][i].second;
                q.push(mp(dis[b],b));
            }else if(dis[b]==dis[a]+c && num[b] > num[a]+w[a][i].second){
                num[b]=num[a]+w[a][i].second;
                p[b]=a;
                q.push(mp(dis[b],b));
            }
        }
    }
    ta = 0;
    for(int i=e;i!=-1;i=p[i]) aa[ta++]=i;
    cTime = dis[e];
}
void dij2(){
    for(int i=0;i<n;++i) p[i]=-1,num[i]=dis[i]=INF,vis[i]=false;
    priority_queue<pp,vector<pp>,cmp> q;
    q.push(mp(0,s));
    dis[s]=num[s]=0;
    for(int a,b,c;!q.empty();){
        pp tem = q.top(); q.pop();
        a = tem.second;
        if(vis[a]) continue;
        vis[a]=true;
        for(int i=0;i<w[a].size();++i){
            b=w[a][i].first; c=w[a][i].second;
            if(vis[b]) continue;
            if(dis[b]>dis[a]+c){
                dis[b]=dis[a]+c;
                num[b]=num[a]+1;
                p[b]=a;
                q.push(mp(dis[b],b));
            }else if(dis[b]==dis[a]+c && num[b] > num[a]+1){
                num[b]=num[a]+1;
                p[b]=a;
                q.push(mp(dis[b],b));
            }
        }
    }
    tb = 0;
    for(int i=e;i!=-1;i=p[i]) bb[tb++]=i;
    cDist = dis[e];
}
bool ok(int *a,int *b){
    for(int i=0;i<max(ta,tb);++i)
        if(a[i]!=b[i]) return true;
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int a,b,c,d,e;m--;){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        t[a].push_back(mp(b,e));
        w[a].push_back(mp(b,d));
        if(c==0){
            t[b].push_back(mp(a,e));
            w[b].push_back(mp(a,d));
        }
    }
    scanf("%d%d",&s,&e);
    dij1();
    dij2();
    if(ok(aa,bb)){
        printf("Time = %d: %d",cTime,aa[ta-1]);
        for(int i=ta-2;i>=0;--i) printf(" => %d",aa[i]); puts("");
        printf("Distance = %d: %d",cDist,bb[tb-1]);
        for(int i=tb-2;i>=0;--i) printf(" => %d",bb[i]); puts("");
    }else{
        printf("Time = %d; Distance = %d: %d",cTime,cDist,aa[ta-1]);
        for(int i=ta-2;i>=0;--i) printf(" => %d",aa[i]); puts("");
    }
    return 0;
}

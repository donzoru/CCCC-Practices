#include<bits/stdc++.h>
using namespace std;;
const int N = 1e5+10;
const int INF = 0x3f3f3f3f;
#define pp pair<int,int>
#define bp pair<pp,int>
#define mp make_pair
int to[N],be[N],he[N],ne[N];
int n,cn,m;
int dis[2][N],pat[2][N];
bool vis[N];
void add(int f,int t,int b){
    to[cn]=t,be[cn]=b,ne[cn]=he[f],he[f]=cn++;
    to[cn]=f,be[cn]=b,ne[cn]=he[t],he[t]=cn++;
}
struct cmp{
    bool operator ()(const bp &a,const bp &b)const {
        return a.first.second > b.first.second;
    }
};
bool dij(int s,int t){
    memset(vis,false,sizeof(vis));
    memset(pat,-1,sizeof(pat));
    for(int i=0;i<N;i++) dis[0][i]=INF,dis[1][i]=0;
    dis[0][s]=0; dis[1][s]=1;
    queue<bp> q; q.push(mp(mp(s,0),0));
    for(int a,b,c,d;q.size();){
        bp t=q.front(); q.pop();
        a = t.first.first; b = t.first.second;
        if(vis[a]) continue;
        vis[a]=true;
        for(int i=he[a];i!=-1;i=ne[i]){
            c = to[i], d = be[i];
            if(vis[c]) continue;
            //cout<< c <<' '<<d<<endl;
            if(dis[0][c] > dis[0][a] + 1){
                dis[0][c] = dis[0][a]+1;
                if(t.second == d) dis[1][c] = dis[1][a];
                else dis[1][c] = dis[1][a]+1;
                pat[0][c] = a;
                pat[1][c] = be[i];
                q.push(mp(mp(c,dis[0][c]),be[i]));
            }else if(dis[0][c] == dis[0][a] + 1){
                if(t.second == d && dis[1][c] > dis[1][a]) {
                    dis[1][c]=dis[1][a];
                    pat[0][c] = a;
                    pat[1][c] = be[i];
                    q.push(mp(mp(c,dis[0][c]),be[i]));
                }else if(t.second !=d && dis[1][c] > dis[1][a]+1){
                    dis[1][c] = dis[1][a]+1;
                    pat[0][c] = a;
                    pat[1][c] = be[i];
                    q.push(mp(mp(c,dis[0][c]),be[i]));
                }
            }
        }
    }
    return dis[0][t]!=INF;
}
void pt(int s,int t){
    printf("%d\n",dis[0][t]);
    vector<bp> ans;
    for(int i=pat[0][t],j=t;i!=-1;j=i,i=pat[0][i])
        ans.push_back(mp(mp(i,j),pat[1][j]));
    int tmp = (int)ans.size()-1;
    int lst = ans[tmp].second;
    printf("Go by the line of company #%d from %04d",lst,ans[tmp].first.first);
    for(int i=tmp-1;i>=0;--i){
        if(ans[i].second==lst) continue;
        else {
            printf(" to %04d.\n",ans[i+1].first.second);
            lst = ans[i].second;
            printf("Go by the line of company #%d from %04d",lst,
                   ans[i].first.first);
        }
    }
    printf(" to %04d.\n",ans[0].first.second);
}
int main(){
    scanf("%d",&n);
    memset(he,-1,sizeof(he));
    for(int i=0;i<n;++i){
        int a,b,c;
        scanf("%d%d",&a,&b);
        for(int j=2;j<=a;++j){
            scanf("%d",&c);
            add(b,c,i+1);
            b = c;
        }
    }
    scanf("%d",&m);
    for(int a,b;m--;){
        scanf("%d%d",&a,&b);
        if(dij(a,b)) pt(a,b);
        else puts("Sorry, no line is available.");
    }
    return 0;
}

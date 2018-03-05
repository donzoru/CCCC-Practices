#include<bits/stdc++.h>
using namespace std;
int p[65][1300][130];
int n,m,l,t,ans;
int dz[]={1,-1,0,0,0,0};
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
void bfs(int z,int x,int y){
    queue<int> q;
    q.push(z);q.push(x);q.push(y);
    int tem=1;
    p[z][x][y]=0;
    while(!q.empty()){
        z=q.front();q.pop();
        x=q.front();q.pop();
        y=q.front();q.pop();
        for(int i=0;i<6;++i){
            int zz=z+dz[i];
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(p[zz][xx][yy]==0) continue;
            q.push(zz),q.push(xx),q.push(yy);
            ++tem; p[zz][xx][yy]=0;
        }
    }
    ans+=tem>=t?tem:0;
}
int main(){
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int k=1;k<=l;++k)
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j) scanf("%d",&p[k][i][j]);
    int tem;
    for(int k=1;k<=l;++k)
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                if(p[k][i][j]==1) bfs(k,i,j);
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int p[65][1300][130];
int n,m,l,t,ans;
int dz[]={1,-1,0,0,0,0};
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
void dfs(int z,int x,int y,int &t){
    ++t;
    p[z][x][y]=0;
    for(int i=0;i<6;++i){
        int zz=z+dz[i];
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(p[zz][xx][yy])
            dfs(zz,xx,yy,t);
    }
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
                if(p[k][i][j]) dfs(k,i,j,tem=0),ans+=(tem>=t?tem:0);
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define M 100100
vector<int> g[M];
double mul[M];
int n,k,a;
double r,z;
#define pp pair<double,int>
#define mp make_pair
#define fi first
#define se second
int main(){
    scanf("%d %lf %lf",&n,&z,&r);
    r = (100-r)/100.0;
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(k==0){
            scanf("%lf",mul+i);
        }else {
            while(k--){
                scanf("%d",&a);
                g[i].push_back(a);
            }
        }
    }
    queue<pp> q; q.push(mp(z,0));
    z = 0;
    while(!q.empty()){
        pp t = q.front(); q.pop();
        if(mul[t.se]){
            z +=  t.fi*mul[t.se];
            continue;
        }
        for(int i=0;i<g[t.se].size();++i){
            int v = g[t.se][i];
            q.push(mp(t.fi*r,v));
        }
    }
    printf("%d\n",(int)z);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
vector<int> g[M];
int a,f,m,n;
bool s[M],flag;
char c;
set<int> ss;
void fin(int x,int d,bool ok){
    if(d >= 5) return;
    if(ok && ss.find(x)!=ss.end()) { flag=false; return; }
    if(!ok) ss.insert(x);
    for(int y:g[x]) fin(y,d+1,ok);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %c %d %d",&a,&c,&f,&m);
        s[a] = (c=='F');
        if(f!=-1) g[a].push_back(f);
        if(m!=-1) g[a].push_back(m);
        s[f] = 0, s[m] = 1;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&f,&m);
        if(s[f]==s[m]){
            puts("Never Mind");
        }else {
            ss.clear(); flag=true;
            fin(f,0,0); fin(m,0,1);
            puts(flag?"Yes":"No");
        }
    }
    return 0;
}

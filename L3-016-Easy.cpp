#include<bits/stdc++.h>
using namespace std;
const int M = 1<<20;
int a[M];
bool v[M];
int n;
string buf,tmp;
void ins(int x){
    int p=1;
    while(v[p]){
        if(x > a[p]) p=p<<1|1;
        else p=p<<1;
    }
    a[p]=x;
    v[p]=true;
}
int fin(int x){
    int p=1;
    while(v[p]){
        if(a[p]==x) return p;
        if(x > a[p]) p=p<<1|1;
        else p=p<<1;
    }
    return -1;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0,j;i<n;++i) cin>>j,ins(j);
    cin>>n; getline(cin,buf);
    for(int x,y,len;n--;){
        getline(cin,buf);
        len=buf.length();
        stringstream ss(buf);
        if(buf[len-1]=='t'){
            ss >> x >> tmp >> tmp >> tmp;
            x=fin(x);
            if(x==-1 || 1!=x) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf[len-1]=='s'){
            ss >> x >> tmp >> y >> tmp >> tmp;
            x = fin(x); y = fin(y);
            if(x==-1 || y==-1 || x/2 != y/2) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf[len-1]=='l'){
            ss >> x>> tmp >> y >> tmp >> tmp >> tmp >> tmp >> tmp;
            x = fin(x); y = fin(y);
            if(x==-1 || y==-1 || (int)log2(x)!=(int)log2(y)) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf.find("parent")!=string::npos){
            ss >> x >>tmp >>tmp>>tmp>>tmp>>y;
            x =fin(x); y=fin(y);
            if(x==-1 || y==-1 || x!=y/2) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else {
            if(buf.find("left")!=string::npos){
                ss >> x >> tmp >> tmp >> tmp >> tmp >> tmp >> y;
                x = fin(x); y=fin(y);
                if(x==-1 || y==-1 || x!=y*2) cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }else {
                ss >> x >> tmp >> tmp >> tmp >> tmp >> tmp >> y;
                x = fin(x); y=fin(y);
                if(x==-1 || y==-1 || x!=y*2+1) cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}

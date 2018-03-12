#include<bits/stdc++.h>
using namespace std;
#define M 10010
string a,b[M];
double t[M],av;
int n,m;
set<string> s;
vector<string> ans;
int main(){
    cin>>n;
    for(int i=0;i<n;++i) cin>>a,s.insert(a);
    cin>>m;
    for(int i=0;i<m;++i) cin>>b[i]>>t[i],av+=t[i];
    av /= (double)m;
    for(int i=0;i<m;++i)
        if(t[i] - av > 1e-5 && s.find(b[i])==s.end()) ans.push_back(b[i]);
    sort(ans.begin(),ans.end());
    if(ans.size()){
        for(auto i:ans) cout<<i<<endl;
    }else {
        cout<<"Bing Mei You"<<endl;
    }
    return 0;
}

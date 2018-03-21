#include<bits/stdc++.h>
using namespace std;
#define M 1010
#define bb bitset<M>
bitset<M> t,a;
struct cmp{
    bool operator ()(const bb &a,const bb &b) const {
        return a.to_string() < b.to_string();
    }
};
map<bb,int,cmp> mp;
int n,k,h;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        getchar(); t.reset();
        while(k--){
            scanf("%d",&h);
            t[h]=true;
        }
        mp[t]++;
    }
    vector<int> ans;
    for(auto i=mp.begin();i!=mp.end();){
        int res=i->second;
        t = i->first;
        for(bool flag=false;;flag=false){
            auto j = i;
            for(++j;j!=mp.end();){
                a = t & (j->first);
                if(a.count()==0) {j++; continue;}
                flag = true;
                t = t|(j->first);
                res += j->second;
                mp.erase(j++);
            }
            if(flag==false) break;
        }
        ans.push_back(res);
        i = mp.erase(i);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;--i) printf("%d%c",ans[i],i==0?'\n':' ');
    return 0;
}

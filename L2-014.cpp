#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    set<int>ss;
    ss.insert(0);
    while(n--){
        cin>>a;
        if(a<(*ss.rbegin()))
            ss.erase(*(ss.upper_bound(a)));
        ss.insert(a);
    }cout<<ss.size()-1;
    return 0;
}

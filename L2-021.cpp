#include<bits/stdc++.h>
using namespace std;
struct pp{
    set<int> s;
    string n;
    int k;
    bool operator < (const pp & a)const {
        if(s.size() == a.s.size()) return s.size()*a.k > a.s.size() * k;
        return s.size() > a.s.size();
    }
};
pp arr[110];
int main(){
    int n;
    cin>>n;
    for(int i=0,a,b;i<n;++i){
        cin>>arr[i].n>>arr[i].k; a=arr[i].k;
        while(a--){
            cin>>b;
            arr[i].s.insert(b);
        }
    }
    sort(arr,arr+n);
    if(n>2) {
        for(int i=0;i<3;++i) cout<<arr[i].n<<(i==2?'\n':' ');
    }else {
        for(int i=0;i<n;++i) cout<<arr[i].n<<' ';
        for(int i=n;i<3;++i) cout<<'-'<<(i==2?'\n':' ');
    }
    return 0;
}

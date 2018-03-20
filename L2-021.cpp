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
/**
5
bob 11 101 102 103 104 105 106 107 108 108 107 107
peter 8 1 2 3 4 3 2 5 1
chris 12 1 2 3 4 5 6 7 8 9 1 2 3
john 10 8 7 6 5 4 3 2 1 7 5
jack 9 6 7 8 9 10 11 12 13 14
*/

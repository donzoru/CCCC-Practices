#include<bits/stdc++.h>
using namespace std;
int n,k,m;
vector<double> arr;
int main()
{
    arr.clear();
    cin>>n>>k>>m;
    while(n--){
        double a,b,c,sum;
        a=sum=0,b=2e10;
        for(int i=0;i<k;++i){
            cin>>c;
            a=max(a,c);
            b=min(b,c);
            sum+=c;
        }
        c=k-2;
        arr.push_back((sum-a-b)/c);
    }
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-m;i<arr.size();++i)
        printf("%.3lf%c",arr[i],i==arr.size()-1?'\n':' ');
    return 0;
}

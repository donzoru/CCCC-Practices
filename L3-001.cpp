#include<bits/stdc++.h>
using namespace std;
const int M = 1e4+2;
int a[M];
int dp[102];
bool has[102][M];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) scanf("%d",a+i);
    memset(dp,0,sizeof(dp));
    memset(has,0,sizeof(has));
    sort(a,a+n);
    for(int i=n-1;i>=0;--i){
        for(int j=m;j>=a[i];--j){
            if(dp[j]<=dp[j-a[i]]+a[i]){
                dp[j]=dp[j-a[i]]+a[i];
                has[j][i]=true;
            }
        }
    }
    if(dp[m]!=m) cout<<"No Solution";
    else {
        vector<int> ans;
        int i=0;
        while(m){
            if(has[m][i]){
                ans.push_back(a[i]);
                m-=a[i];
            }
            ++i;
        }
        for(int i=0;i<ans.size();++i)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return 0;
}

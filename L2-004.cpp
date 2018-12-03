#include<bits/stdc++.h>
using namespace std;
const int M = 1002;
int a[M];
int n;
bool mirror;
vector<int> tra;
void getpost(int root,int tail)
{
    if(root>tail) return;
    int i=root+1,j=tail;
    if(!mirror){
        while(i<=tail && a[i]<a[root]) ++i;
        while(j>root && a[j]>=a[root]) --j;
    }else {
        while(i<=tail && a[i]>=a[root]) ++i;
        while(j>root && a[j]<a[root]) --j;
    }
    if(i-j!=1) return;
    getpost(root+1,j);
    getpost(i,tail);
    tra.push_back(a[root]);
}
int main()
{
    cin>>n;
    mirror=false;
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    getpost(0,n-1);
    if(tra.size()!=n){
        mirror=true;
        tra.clear();
        getpost(0,n-1);
    }
    if(tra.size()==n){
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)
            printf("%d%c",tra[i],i==n-1?'\n':' ');
    }else cout<<"NO";
    return 0;
}

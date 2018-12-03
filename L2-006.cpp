#include<bits/stdc++.h>
using namespace std;
int a[32],b[32];
struct tree{
    int n;
    tree *l,*r;
}*root;
void build(int as,int ae,int bs,int be,tree*& root)
{
    //cout<<as<<' '<<ae<<' '<<bs<<' '<<be<<endl;
    root->n=a[ae];
    //cout<<a[ae]<<endl;
    int t=find(b+bs,b+be,a[ae])-b;
    if(t-1<bs) root->l=NULL;
    else{
        root->l = new tree;
        build(as,as+t-bs-1,bs,t-1,root->l);
    }
    if(t+1>be) root->r=NULL;
    else {
        root->r = new tree;
        build(as+t-bs,ae-1,t+1,be,root->r);
    }
}
void floor()
{
    queue<tree *> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->n);
        if(q.front()->l) q.push(q.front()->l);
        if(q.front()->r) q.push(q.front()->r);
        q.pop();
    }
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<(i==ans.size()-1?'\n':' ');
}
int main()
{
    int n;
    cin>>n;
    root=new tree;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    build(0,n-1,0,n-1,root);
    floor();
    return 0;
}

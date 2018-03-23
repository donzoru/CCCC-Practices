#include<bits/stdc++.h>
using namespace std;
int a[32],b[32];
struct tree{
    int n;
    tree *l,*r;
}*root;
void build(int as,int ae,int bs,int be,tree*& root)
{
    root->n=b[bs];
    int t=find(a+as,a+ae,b[bs])-a;
    if(t-1<as) root->l=NULL;
    else{
        root->l = new tree;
        build(as,t-1,bs+1,bs+t-as,root->l);
    }
    if(t+1>ae) root->r=NULL;
    else{
        root->r = new tree;
        build(t+1,ae,bs+1+t-as,be,root->r);
    }
}
void level()
{
    queue<tree*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->n);
        if(q.front()->r) q.push(q.front()->r);
        if(q.front()->l) q.push(q.front()->l);
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
    level();
    return 0;
}

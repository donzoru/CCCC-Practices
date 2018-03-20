#include<bits/stdc++.h>
using namespace std;
int n;
string buf,tmp;
struct bst{
    int key,L;
    bst * nxt[3];
    bst(){};
    bst(int key):key(key){
        nxt[0]=nxt[1]=nxt[2]=NULL;
        L = 1;
    };
};
bst * rt;
void ins(bst *&r,bst *f,int x){
    if(r==NULL){
        r = new bst(x); r->nxt[2]=f;
        if(f==NULL) return;
        r->L = f->L+1;
        if(f->key > x) f->nxt[0]=r;
        else f->nxt[1]=r;
        return;
    }
    if(x > r->key) ins(r->nxt[1],r,x);
    else ins(r->nxt[0],r,x);
}
bst* fin(int x){
    bst * p = rt;
    while(p!=NULL){
        if(x == p->key) return p;
        if(x > p->key) p = p->nxt[1];
        else p = p->nxt[0];
    }
    return NULL;
}
void bfs(){
    queue<bst*> q;
    q.push(rt);
    while(q.size()){
        bst * t = q.front(); q.pop();
        cout<<t<<' '<<t->key<<' '<<t->L<<' '<<
        t->nxt[0]<<' '<<t->nxt[1]<<' '<<t->nxt[2]<<endl;
        if(t->nxt[0]) q.push(t->nxt[0]);
        if(t->nxt[1]) q.push(t->nxt[1]);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n; rt=NULL;
    for(int i=0,j;i<n;++i) cin>>j,ins(rt,NULL,j);
    //bfs();
    cin>>n; getline(cin,buf);
    bst *a,*b;
    for(int x,y,len;n--;){
        getline(cin,buf);
        len=buf.length();
        stringstream ss(buf);
        if(buf[len-1]=='t'){
            ss >> x >> tmp >> tmp >> tmp;
            a=fin(x);
            if(a==NULL || a!=rt) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf[len-1]=='s'){
            ss >> x >> tmp >> y >> tmp >> tmp;
            a = fin(x); b = fin(y);
            if(a==NULL || b==NULL || a->nxt[2]!=b->nxt[2]) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf[len-1]=='l'){
            ss >> x>> tmp >> y >> tmp >> tmp >> tmp >> tmp >> tmp;
            a = fin(x); b = fin(y);
            if(a==NULL || b==NULL || a->L!=b->L) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else if(buf.find("parent")!=string::npos){
            ss >> x >>tmp >>tmp>>tmp>>tmp>>y;
            a =fin(x); b=fin(y);
            if(a==NULL || b==NULL || a!=b->nxt[2]) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else {
            if(buf.find("left")!=string::npos){
                ss >> x >> tmp >> tmp >> tmp >> tmp >> tmp >> y;
                a = fin(x); b=fin(y);
                if(a==NULL || b==NULL || a!=b->nxt[0]) cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }else {
                ss >> x >> tmp >> tmp >> tmp >> tmp >> tmp >> y;
                a= fin(x); b=fin(y);
                if(a==NULL || b==NULL || a!=b->nxt[1]) cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define N 100005
const int M = 1e5+10;
int t[M<<2],cnt,n;
int sta[M],a;
char s[20];
void ins(int l,int r,int p,int x){
    ++t[p];
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) ins(lson,x);
    else ins(rson,x);
}
void del(int l,int r,int p,int x){
    --t[p];
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) del(lson,x);
    else del(rson,x);
}
int sea(int l,int r,int p,int k){
    if(l==r) return l;
    int m=l+r>>1;
    if(t[p<<1] >=k ) return sea(lson,k);
    else return sea(rson,k-t[p<<1]);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int len=strlen(s);
        if(len==3){
            if(cnt) del(1,N,1,sta[cnt-1]),printf("%d\n",sta[--cnt]);
            else puts("Invalid");
        }else if(len==10){
            if(cnt) {
                if(cnt%2) printf("%d\n",sea(1,N,1,(cnt+1)/2));
                else printf("%d\n",sea(1,N,1,cnt/2));
            }else {
                puts("Invalid");
            }
        }else if(len==4){
            scanf("%d",&a);
            sta[cnt++]=a; ins(1,N,1,a);
        }
    }
    return 0;
}
/**
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
*/
/**
#include<bits/stdc++.h>
using namespace std;
#define M 2e5+10
int sta[100100],t;
set<int> ss;
int n,a;
char s[20];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int len=strlen(s);
        if(len==3){
            if(t) ss.erase(sta[t-1]),printf("%d\n",sta[--t]);
            else puts("Invalid");
        }else if(len==10){
            if(t) {
                auto it = ss.begin();
                if(t%2) advance(it,(ss.size()+1)/2-1),printf("%d\n",*it);
                else advance(it,ss.size()/2-1),printf("%d\n",*it);
            }else {
                puts("Invalid");;
            }
        }else {
            scanf("%d",&a);
            sta[t++]=a; ss.insert(a);
        }
    }
    return 0;
}
*/

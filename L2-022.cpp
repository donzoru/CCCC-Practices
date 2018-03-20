#include<bits/stdc++.h>
using namespace std;
#define M 100010
int add[M],data[M],nex[M];
int n,head,tem;
int a[M],b[M],cnt;
int main(){
    scanf("%d%d",&head,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        add[tem] = tem;
        scanf("%d%d",data+tem,nex+tem);
    }
    cnt = tem = 0;
    for(int i=head;i!=-1;i=nex[i]) a[cnt++]=i;
    int l = 0,r=cnt-1;
    while(l <= r){
        if(l==r) b[tem++]=a[r--];
        else b[tem++]=a[r--],b[tem++]=a[l++];
    }
    for(int i=0;i<cnt-1;++i) printf("%05d %d %05d\n",b[i],data[b[i]],b[i+1]);
    printf("%05d %d -1\n",b[cnt-1],data[b[cnt-1]]);
    return 0;
}

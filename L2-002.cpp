#include<bits/stdc++.h>
using namespace std;
#define cls(a) a.clear()
const int M = 1e5+5;
struct ifo{
    int add,num,nex,k;
    bool operator <(const ifo &a)const {
        return k<a.k;
    }
}aa[M];
map<int,bool>has;
int main()
{
    int n,beg;
    cin>>beg>>n;
    cls(has);
    int add,a=0,b=0;
    for(int i=0;i<M;++i)
        aa[i].k=M*2;
    while(n--){
        cin>>add;
        aa[add].add=add;
        cin>>aa[add].num>>aa[add].nex;
    }
    for(int i=beg;i!=-1;i=aa[i].nex){
        if(has[abs(aa[i].num)]==true){
            aa[i].k=100000+(b++);
        }
        else{
            has[abs(aa[i].num)]=true;
            aa[i].k=a++;
        }
    }
    sort(aa,aa+M);
    b+=a;
    for(int i=0;i<b;++i)
        if(i!=a-1 && i!=b-1) printf("%05d %d %05d\n",aa[i].add,aa[i].num,aa[i+1].add);
        else printf("%05d %d -1\n",aa[i].add,aa[i].num);
    return 0;
}

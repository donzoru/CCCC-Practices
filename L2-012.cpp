#include<bits/stdc++.h>
using namespace std;
string str,tem;
int n,m,a,b;
vector<int> heap;
int getP(int k){
    return distance(heap.begin(),find(heap.begin(),heap.end(),k));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a),heap.push_back(a),
    make_heap(heap.begin(),heap.end(),greater<int>() ); getchar();
    while(m--){
        getline(cin,str);
        int len = str.length();
        if(str[len-1]=='t'){
            stringstream buf(str);
            buf >> a;
            if(a==heap[0]) puts("T");
            else puts("F");
        }else if(str[len-1]=='s'){
            stringstream buf(str);
            buf >> a >> tem >> b;
            a = getP(a); ++a;
            b = getP(b); ++b;
            if(a/2 == b/2) puts("T");
            else puts("F");
        }else if(str.find("the")!=string::npos){
            stringstream buf(str);
            buf >> a >> tem >> tem >> tem >> tem >> b;
            a = getP(a); ++a;
            b = getP(b); ++b;
            if(a == b/2) puts("T");
            else puts("F");
        }else {
            stringstream buf(str);
            buf >> a >> tem >> tem >> tem >> tem >> b;
            a = getP(a); ++a;
            b = getP(b); ++b;
            if(a/2 == b) puts("T");
            else puts("F");
        }
    }
    return 0;
}
/**
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
*/

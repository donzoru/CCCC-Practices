#include<bits/stdc++.h>
using namespace std;
const double g = 9.8;
const double eps = 1e-8;
const double pi = 3.1415926;
double w,p,e;
double calu(double a){
    double sv = sin(a),cv = cos(a),res=0;
    double e = 1000.0;
    while(fabs(e-0)>eps){
        double v = sqrt(2*100*e/w);
        double t = 2*sv*v/g;
        res += cv*v*t;
        e = (1-p/100)*e;
    }
    return res;
}
int main(){
    scanf("%lf%lf",&w,&p);
    printf("%.3f\n",calu(pi/4));
    return 0;
}

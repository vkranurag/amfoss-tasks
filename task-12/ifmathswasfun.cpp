#include<bits/stdc++.h>
using namespace std;
double b,c;
double fx(double x)
{
    return (x*x+b*x+c)/sin(x);
}
double tsearch(double l, double r) {
    double e = 1e-7;
    while (r - l > e) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = fx(m1);
        double f2 = fx(m2);
        if (f1 > f2)l = m1;
        else r = m2;
    }
    return fx(l);
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>b>>c;
        cout<<setprecision(8)<<tsearch(0,M_PI/2)<<endl;
    }
    return 0;
}

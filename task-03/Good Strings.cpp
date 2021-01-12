#include <bits/stdc++.h>

using namespace std;
 
typedef long long int ll;

#define cnt(a,x) count(a.begin(),a.end(),x);

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll one=cnt(s,'1');
    ll two=cnt(s,'0');
    if(one!=two)cout<<1;
    else cout<<2;
    return 0;
}
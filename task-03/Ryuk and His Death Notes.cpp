#include <bits/stdc++.h>

using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;

#define read(s) fl(i,s.size())cin>>s[i];
#define fl(i, b) for (int i=0; i<(b); i++)
#define inf INT_MAX

int main(){
    ll n;
    cin>>n;
    vl a(n),b(n);
    read(a);
    read(b);
    ll c=inf;
    fl(i,n){
        c=min(c,(ll)b[i]/a[i]);
    }
    cout<<c;
    return 0;
}
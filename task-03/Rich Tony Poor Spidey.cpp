#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vl;
 
#define fl(i, b) for (int i=0; i<(b); i++)
#define read(s) fl(i,s.size())cin>>s[i];
#define rsor(s) sort(s.rbegin(),s.rend());

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vl a(n);
        read(a);
        rsor(a);
        a[0]-=k;
        ll prod=1;
        fl(i,n)prod*=a[i];
        cout<<prod<<'\n';
    }
    return 0;
}

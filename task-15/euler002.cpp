#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    long s[t];
    long f[100];
    f[0]=1;
    f[1]=2;
    for(int i=2; i<100;++i){
            f[i]=f[i-1]+f[i-2];
    }
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        s[a0]=2;    
        for(int i=2; i<100;++i){
            if(f[i]%2==0&&f[i]<n){
                s[a0]+=f[i];
            }
            else if(f[i]>n){
                break;
            }        
        }        
    }
    for(int a0 = 0; a0 < t; a0++){
        cout<<s[a0]<<endl;
    }      
    return 0;
}

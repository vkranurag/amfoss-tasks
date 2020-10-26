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

using namespace std;


long pf(long n)  
{   long max=1; 
    while (n % 2 == 0)  
    {          
        n = n/2;
        max=2;  
    }
    for (long i = 3; i <= sqrt(n); i = i + 2)  
    {    
        while (n % i == 0)  
        {             
            max=i;
            n = n/i;  
        }  
    }  
    if (n > 2){          
        max=n;
    }
    return max;  
}
int main(){
    long t;
    cin >> t;
    long s[t];
    for(long a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        s[a0]=pf(n);               
    }
    for(long a0 = 0; a0 < t; a0++){
       cout<<s[a0]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
#define fl(i, b) for (int i=0; i<(b); i++)

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string name;
            cin.ignore();
            getline(cin,name);
            stringstream ss(name); 
            int chance=0;
            do{ 
                    string word; 
                    ss >> word; 
                    ll sum=0;
                    if(chance==n && word.size()){
                        fl(i,word.size())
                            sum+=word[i];
                        cout<<sum<<endl;
                        goto z;
                    }
                        chance++;
               }while (ss); 
                  cout<<-1<<endl;
            z:;
        }
    return 0;
}

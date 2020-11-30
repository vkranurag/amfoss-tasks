#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main() {
    int strl;
    char str[1000],arr0[1000],arr1[1000];
    cin>>strl;
    cin>>str;
    int a=strlen(str);
    for(int i=0;i<a;i++)
    {
        if(str[i]=='1')
        {
            arr1[i] = str[i];
        }
        else
        {
            arr0[i] = str[i];
        }
    }
    if (strlen(arr1) == strlen(arr0))
    {
        cout<<2;
    }
    else
    {
        cout<<1;
    }
    return 0;
}

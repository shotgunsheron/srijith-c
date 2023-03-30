#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    int res=0;
    for (int i=0;i<x.length();i++){
        x[i]=tolower(x[i]);
        y[i]=tolower(y[i]);
        if (x[i]<y[i]){
            res=-1;
            break;
        } else if (x[i]>y[i]){
            res=1;
            break;
        }
        

    }
    cout<<res<<'\n';
    //cout<<x<<y<<'\n';
}
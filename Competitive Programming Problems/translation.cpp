#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    string y;
    cin>>x>>y;
    
    string s="";
    for (int i=x.length()-1;i>=0;i--){
        s+=x[i];
    }
    if (s==y){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
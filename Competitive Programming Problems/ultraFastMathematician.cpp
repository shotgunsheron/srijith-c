#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin>>x;
    string y;
    cin>>y;


    string res="";
    //cout<<x<<'\n';
    //cout<<y<<'\n';
    for (int i=0;i<x.length();i++){
        if (x[i]==y[i]){
            res+='0';
        } else{
            res+='1';
        }
    }
    cout<<res<<'\n';
}
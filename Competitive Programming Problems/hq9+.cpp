#include <bits/stdc++.h>

using namespace std;

int main(){
    string p;
    cin>>p;
    bool res=false;
    for (int i=0;i<p.length();i++){
        if (p[i]=='H' or p[i]=='Q' or p[i]=='9'){
            res=true;
            break;
        }
    }
    if (res){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
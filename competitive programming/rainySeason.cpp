#include <bits/stdc++.h>
using namespace std;


int main(){
    string s; cin>>s;
    if (s=="RRR"){
        cout<<3<<'\n';
    } else if (s=="RRS" or s=="SRR"){
        cout<<2<<'\n'; 
    } else if (s=="RSS" or s=="SSR" or s=="SRS" or s=="RSR"){
        cout<<1<<'\n';
    }  else{
        cout<<0<<'\n';
    }
}
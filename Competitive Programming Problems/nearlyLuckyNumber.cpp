#include <bits/stdc++.h>
using namespace std;

int main(){
    uint64_t s;
    cin>>s;
    bool res=true;
    int luckyDigits=0;

    string n=to_string(s);
    //cout<<s<<'\n';

    for (int i=0;i<n.length();i++){
        if (n[i]=='4' or n[i]=='7'){
            //cout<<i<<'\n';
            luckyDigits++;
        }
    }
    //cout<<luckyDigits<<'\n';
    //cout<<n.length()<<'\n';
    string l=to_string(luckyDigits);
    //cout<<l<<'\n';
    for (int k=0;k<l.length();k++){
        if (l[k]!='4' and l[k]!='7'){
            res=false;
        }
    }
    if (res){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int t=s.length();
    vector<char> res;
    for (int i=0;i<t-1;i++){
        if (s[i]=='-' and s[i+1]=='-'){
            res.push_back('2'); 
            s[i]=' ';
            s[i+1]=' ';
        }
        else if (s[i+1]=='.' and s[i]=='-'){
            res.push_back('1');
            s[i]=' ';
            s[i+1]=' ';
        } else if (s[i+1]=='.' and s[i]!='-'){
            res.push_back('0');
            s[i+1]=' ';
        }
    }
    //cout<<s<<'\n';
    bool frontZero=false;
    if (s[0]=='.'){
        frontZero=true;
        s[0]==' ';
    }
    string resStr;
    if (frontZero){
        resStr+='0';
    }
    for (int k=0;k<res.size();k++){
        resStr+=res[k];
    }
    cout<<resStr<<'\n';
    //cout<<s<<'\n';
}
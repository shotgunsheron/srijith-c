#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string res="";
    for (int k=0;k<s.length();k++){
        s[k]=::tolower(s[k]);

    }
    for (int i=0;i<s.length();i++){
        if (s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u' and s[i]!='y'){
            res+='.';
            res+=s[i];
        }
    }
    cout<<res<<'\n';
}
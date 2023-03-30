#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string hello="hello";
    string res="";
    int currPos=0;
    for (int i=0;i<s.length();i++){
        if (s[i]==hello[currPos]){
            res+=hello[currPos];
            currPos++;
        }
    }
    if (res==hello){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}

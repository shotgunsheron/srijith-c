#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int a=1;
    int b=1;
    bool currA=true;
    if (s[0]=='0'){
        currA=true;
    } else{
        currA=false;
    }
    bool dangerous=false;
    for (int i=1;i<s.length();i++){
        if (a>=7 or b>=7){
            dangerous=true;
        }
        if (s[i]==s[i-1] and s[i]=='0'){
            a++;
        } else if (s[i]==s[i-1] and s[i]=='1'){
            b++;
        } else if (s[i]!=s[i-1] and s[i-1]=='0'){
            if (a>=7){
                dangerous=true;
            }
            a=0;
            b++;
        } else if (s[i]!=s[i-1] and s[i-1]=='1'){
            if (b>=7){
                dangerous =true;

            }
            b=0;
            a++;
        }
        //cout<<a<<'\n';
        //cout<<b<<'\n';
    }
    if (dangerous){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
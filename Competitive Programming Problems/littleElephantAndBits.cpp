#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    string res="";
    if (count(a.begin(),a.end(),'0')){
        bool firstZero=false;
        for (int i=0;i<a.length();i++){
            if (a[i]=='0' and firstZero==false){
                firstZero=true;
            } else{
                res+=a[i];
            }
        }
    }  else{
        for (int i=0;i<a.size()-1;i++){
            res+='1';
        }
    }
    cout<<res<<'\n';
}


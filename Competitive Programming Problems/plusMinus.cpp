#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
    int n; cin>>n;
    string res="";
    bool cur=false; //if false then currently neutral, if true then trying to cancel out a 1
    for (int i=0;i<n;i++){
        char x; cin>>x;
        if (i==0){
            if (x=='1'){
                cur=true;
            }
        } else{
            if (x=='1' and cur==true){
                res+='-';
                cur=false;
            } else if (x=='1' and cur==false){
                cur=true;
                res+='+';
            } else{
                res+='+';
            }
        }
    }
    cout<<res<<'\n';
}
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        bool ans=true;
        for (long long i=1;i<=n;i++){
            long long x; cin>>x;
            bool curAns=false;
            for (long long j=2;j<=i+1;j++){
                if (x%j!=0){
                    curAns=true;
                    break;
                }
            }
            ans&=curAns;
        }
        if (ans){
            cout<<"YES"<<'\n';
        } else{
            cout<<"NO"<<'\n';
        }
    }
}
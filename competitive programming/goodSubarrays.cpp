#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
    long long n; cin>>n;
    string a; cin>>a;
    long long s=0;
    long long ans=0;
    map<long long,long long> mp;
    mp[0]=1;
    for (long long i=0;i<a.length();i++){
        s+=a[i]-'0';
        ans+=mp[s-(i+1)];
        mp[s-(i+1)]++;
    }
    cout<<ans<<'\n';
    }
}
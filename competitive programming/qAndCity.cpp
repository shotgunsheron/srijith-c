#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
    long long n; cin>>n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long alternating=0;
    long long ans=0;
    
    for (long long i=1;i<n-1;i+=2){

        ans+=max((long long)0,1+max(a[i-1],a[i+1])-a[i]);
    }

    if (n%2==1){
        cout<<ans<<'\n';
    } else{
        long long finalAns=ans;
        for (long long i=n-3;i>0;i-=2){
            //cout<<a[i]<<'\n';
            ans-=max((long long)0,1+max(a[i-1],a[i+1])-a[i]);
            ans+=max((long long)0,1+max(a[i],a[i+2])-a[i+1]);
            finalAns=min(finalAns,ans);
        }
        cout<<finalAns<<'\n';
    }
    }

    
}
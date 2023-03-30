#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long> arr(n);
        for (long long i=0;i<n;i++){
            cin>>arr[i];
        }
        long long ans=0;
        for (long long i=30;i>=0;i--){
            long long count=0;
            for (long long j=0;j<arr.size();j++){
                long long x=arr[j];
                if ((long long)(x | (long long)pow(2,i))==arr[j]){
                    count++;
                }
            }
            if (count==n){
                ans+=pow(2,i);
            }
            else if (n-count<=k){
                k-=(n-count);
                ans+=pow(2,i);
            }
        }
        cout<<ans<<'\n';
    }
}
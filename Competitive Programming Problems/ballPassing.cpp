#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> arr(n);
        for (long long i=0;i<n;i++){
            cin>>arr[i];
        }
        long long maxNum=0;
        long long sum=0;
        for (long long i=0;i<n;i++){
            maxNum=max(maxNum,arr[i]);
            sum+=arr[i];
        }
        if (sum==0){
            cout<<0<<'\n';
        }
        else if (maxNum<=(sum-maxNum)){
            cout<<1<<'\n';
        } else{
            cout<<maxNum-(sum-maxNum)<<'\n';
        }
    }
}
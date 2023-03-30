#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0;
        sort(arr.begin(),arr.end());
        for (int i=0;i<n-2*k;i++){
            ans+=arr[i];
        }
        for (int i=0;i<k;i++){
            ans+=arr[n-2*k+i]/arr[n-k+i];
        }
        cout<<ans<<'\n';    
    }
}
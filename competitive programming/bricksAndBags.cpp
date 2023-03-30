#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for (int i=0;i<n-1;i++){
        ans=max(ans,v[i+1]-v[i]+v[n-1]-v[i]);
    }
    for (int i=1;i<n-1;i++){
        ans=max(ans,v[i+1]-v[i]+v[i+1]-v[0]);
    }
    cout<<ans<<'\n';
    }
}
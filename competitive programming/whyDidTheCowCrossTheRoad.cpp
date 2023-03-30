#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,b; cin>>n>>k>>b;

    vector<int> p;
    while(b--){
        int x; cin>>x;
        p.push_back(x);
    }
    sort(p.begin(),p.end());
    vector<int> arr;
    int pSum=0;
    int currP=0;
    for (int i=1;i<=n;i++){
        if (i==p[currP]){
            pSum++;
            if (currP!=p.size()-1){
                currP++;
            }
        }
        arr.push_back(pSum);
    }
    int ans=arr[k-1];
    for (int i=k;i<arr.size();i++){
        int brokenSignals=arr[i]-arr[i-k];
        ans=min(ans, brokenSignals);
    }
    cout<<ans<<'\n';
}
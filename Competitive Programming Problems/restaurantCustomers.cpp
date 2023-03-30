#include <bits/stdc++.h>
using namespace std;


bool cmp(vector<int> a,vector<int>b){
    return a[0]<b[0];
}

int main(){
    int n; cin>>n;
    vector<vector<int>> times;
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        times.push_back({x,1});
        times.push_back({y,-1});
    }
    sort(times.begin(),times.end(),cmp);
    int ans=0;
    int cur=0;
    for (int i=0;i<times.size();i++){
        cur+=times[i][1];
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';

}
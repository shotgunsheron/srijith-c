#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> uh;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            uh.push_back(x);
        }
        vector<vector<int>> adj_list;
        vector<int> degrees(n+1,0);
        for (int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            degrees[x]++;
            degrees[y]++;
            adj_list.push_back({x,y});
        }
        int ans=INT_MAX;
        for (int i=1;i<=n;i++){
            if (degrees[i]%2==1){
                ans=min(ans,uh[i-1]);
            }
        }
        for (int i=0;i<adj_list.size();i++){
            if ((degrees[adj_list[i][0]]+degrees[adj_list[i][1]])%2==0){
                ans=min(ans,uh[adj_list[i][0]-1]+uh[adj_list[i][1]-1]);
            }
        }
        if (m%2==0){
            cout<<0<<'\n';
        } else{
            cout<<ans<<'\n';
        }
    }
}
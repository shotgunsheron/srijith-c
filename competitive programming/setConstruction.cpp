#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> graph(n);
        for (int i=0;i<n;i++){
            string s; cin>>s;
            for (int j=0;j<n;j++){
                if (s[j]=='1'){
                    graph[j].push_back(i);
                }
            }
        }
        for (int i=0;i<n;i++){
            int x=graph[i].size();
            cout<<x+1<<' ';
            for (int i=1;i<=x+1;i++){
                cout<<i<<' ';
            }
            cout<<'\n';
        }
    }
}
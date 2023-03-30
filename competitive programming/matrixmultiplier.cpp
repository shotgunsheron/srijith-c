#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n; cin>>m>>n;
    int x,y; cin>>x>>y;
    vector<vector<int>> a(m);
    vector<vector<int>> b(x);

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            int r; cin>>r;
            a[i].push_back(r);
        }
    }
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            int r; cin>>r;
            b[i].push_back(r);
        }
    }
    vector<vector<int>> res(m,vector<int>(y));
    for (int i=0;i<m;i++){
        for (int j=0;j<y;j++){
            
        }
    }




}
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a,vector<int>b){
    if (a[1]==b[1]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}

int main(){
    int n; cin>>n;
    vector<vector<int>> movies;
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        movies.push_back({x,y});
    }
    sort(movies.begin(),movies.end(),cmp);
    int curEnd=movies[0][1];
    int ans=1;
    for (int i=1;i<n;i++){
        if (movies[i][0]>=curEnd){
            ans++;
            curEnd=movies[i][1];
        }
    }
    cout<<ans<<'\n';
}
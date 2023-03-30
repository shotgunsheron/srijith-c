#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>puzzles;
    while(m--){
        int x;
        cin>>x;
        puzzles.push_back(x);
    }
    sort(puzzles.begin(),puzzles.end());
    int maxDiff=puzzles[n-1]-puzzles[0];
    for (int i=0;i<=puzzles.size()-n;i++){
        //cout<<puzzles[i+n-1]-puzzles[i]<<'\n';
        if (puzzles[i+n-1]-puzzles[i]<maxDiff){
            maxDiff=puzzles[i+n-1]-puzzles[i];
        }
    }
    cout<<maxDiff<<'\n';
}
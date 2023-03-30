#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if (a[1]==b[1]){
        return a[0]<b[0];
    } else{
        if (a[1]==0 and b[1]==1){
            return true; 
        } 
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> arr;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            arr.push_back({x});
        }
        string s; cin>>s;
        for (int i=0;i<n;i++){
            if (s[i]=='B'){
                arr[i].push_back(0);
            } else{
                arr[i].push_back(1);
            }
        }
        sort(arr.begin(),arr.end(),cmp);
        bool ans=true;
        for (int i=0;i<arr.size();i++){
            if (arr[i][1]==0 and arr[i][0]<i+1){
                ans=false;
                break;
            } else if (arr[i][1]==1 and arr[i][0]>i+1){
                ans=false;
                break;
            }
        }
        if (ans){
            cout<<"YES"<<'\n';
        } else{
            cout<<"NO"<<'\n';
        }
    }


}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<int> arr;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                int distA=abs(i-1)+abs(j-1);
                int distB=abs(i-1)+abs(m-j);
                int distC=abs(n-i)+abs(j-1);
                int distD=abs(n-i)+abs(m-j);
                arr.push_back(max(max(distA,distB),max(distC,distD)));
            }
        }
        sort(arr.begin(),arr.end());
        for (int i=0;i<n*m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    vector<int> arr(19,0);
    vector<vector<int>> pSum;
    pSum.push_back(arr);
    for (int i=1;i<=2*200000;i++){
        for (int j=0;j<=18;j++){
            if ((i&(int)(pow(2,j)))==(int)pow(2,j)){
                arr[j]++;
            }
        }
        pSum.push_back(arr);
    }

    int t; cin>>t;
    while(t--){
    //18 bits to check
    int ans=0;
    int l,r; cin>>l>>r;
    for (int i=0;i<=18;i++){
        ans=max(ans,pSum[r][i]-pSum[l-1][i]);
    }
    
    cout<<r-l+1-ans<<'\n';
    }
}
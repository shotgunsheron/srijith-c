#include <bits/stdc++.h>
using namespace std;


bool cmp(vector<int> a, vector<int> b){
    return (a[1]-a[0]>b[1]-b[0]);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=0;
        int currCount=0;
        int currVal=arr[0];
        vector<vector<int>> ans;
        
        while(l<arr.size() and r<arr.size()){
            if (arr[r]==currVal){
                currCount++;
                if (currCount==k){
                    ans.push_back({arr[l],arr[r]});
                }
                r++;
            } else if (arr[r]==currVal+1){
                if (currCount<k){
                    l=r;
                } 
                currCount=1;
                currVal=arr[r];
                if (currCount==k){
                    ans.push_back({arr[l],arr[r]});
                }
                r++;
            } else{
                l=r;
                currCount=0;
                currVal=arr[l];
            }
        }
        if (ans.size()>0){
            sort(ans.begin(),ans.end(),cmp);
            cout<<ans[0][0]<<' '<<ans[0][1]<<'\n';
        } else{
            cout<<-1<<'\n';
        }
    }

}
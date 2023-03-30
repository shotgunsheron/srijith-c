#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    vector<int> arr;
    while(n--){
        int x; cin>>x;
        arr.push_back(x);
    }
    int minVal=0;
    int maxVal=int(1e9);
    for (int i=0;i<arr.size()-1;i++){
        int x=arr[i]; int y=arr[i+1];
            int midL = (x + y) / 2;
            int midR = (x + y + 1) / 2;
        if (x<y){
            maxVal=min(maxVal,midL);
        } else if (x>y){
            minVal=max(minVal, midR);
        }
    }
    if (minVal<=maxVal){
        cout<<minVal<<'\n';
    } else{
        cout<<-1<<'\n';
    }
    }

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int nT=n;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    if (count(arr.begin(),arr.end(),arr[0])==arr.size()){
        cout<<0<<'\n';
    }
    else if (count(arr.begin()+k-1,arr.end(),arr[k-1])==nT-k+1){
        //int e=1;
        //while(count(arr.begin()+e-1,arr.end(),arr[e-1])!=nT-e+1){
        //    e++;
        //}
        //cout<<e-1<<'\n';
        int target=arr[k-1];
        while(arr[k-1]==target){
            k--;
        }
        cout<<k<<'\n';
    } else{
        cout<<-1<<'\n';
    }
}
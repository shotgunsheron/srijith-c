#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> arr;
    while(n--){
        long long x; cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),greater<long long>());
    long long maxMoney=0;
    long long minTuition=0;
    for (long long i=0;i<arr.size();i++){
        long long money=(i+1)*arr[i];
        maxMoney=max(maxMoney,money);
        if (money>=maxMoney){
            minTuition=arr[i];
        }
    }
    cout<<maxMoney<<' '<<minTuition<<'\n';
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<vector<long long>> square;
    long long sum=0;
    for (long long i=0;i<n;i++){
        vector<long long> tmp;
        for (long long j=0;j<n;j++){
            long long x; cin>>x;
            sum+=x;
            tmp.push_back(x);
        }
        square.push_back(tmp);
    }
    long long minVal=sum;
    for (int i=0;i<n;i++){
        minVal=min(minVal,square[i][n-i-1]);
    }
    cout<<sum-minVal<<'\n';
}
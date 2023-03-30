#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    vector<int> arr(n,0);
    for (int i=0;i<k;i++){
        int x, y; cin>>x>>y;
        arr[x-1]++;
        arr[y-1]--;
    }
    vector<int> p;
    int pSum=0;
    for (int i=0;i<arr.size();i++){
        pSum+=arr[i];
        p.push_back(pSum);
    }
    sort(p.begin(),p.end());
    cout<<p[p.size()/2]<<'\n';

}
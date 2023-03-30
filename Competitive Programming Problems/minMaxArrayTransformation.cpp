#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a,b;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for (int i=0;i<n;i++){
        int x; cin>>x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=0; int r=0;
    vector<int> minArr;
    while(r<n){
        if (a[r]>b[l]){
            l++;
        } else{
            minArr.push_back(b[l]-a[r]);
            //cout<<b[l]-a[r]<<'\n';
            r++;
        }
    }
    l=n-1;
    r=n-1;
    vector<int> maxArr;
    while(l>=0 and r>=0){
        if (a[l]<b[r]){
            cout<<l<<' '<<r<<'\n';

            maxArr.push_back(b[l]-a[r]);
            r--;
        } else{
            l=r;
        }
    }
    for (int i=0;i<minArr.size();i++){
        cout<<minArr[i]<<' ';
    }
    cout<<'\n';
    for (int i=maxArr.size()-1;i>=0;i--){
        cout<<maxArr[i]<<' ';
    }
    cout<<'\n';
}
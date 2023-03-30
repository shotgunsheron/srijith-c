#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>res;
    res.push_back(n);
    for (int i=1;i<n;i++){
        res.push_back(i);
    }
    for (int k=0;k<res.size();k++){
        cout<<res[k]<<' ';
    }
    
}
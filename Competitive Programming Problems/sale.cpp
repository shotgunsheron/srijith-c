#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> tvs;
    while(n--){
        int x;
        cin>>x;
        tvs.push_back(x);
    }
    sort(tvs.begin(),tvs.end());
    int res=0;
    for (int i=0;i<m;i++){
        if (tvs[i]<=0){
            res+=tvs[i];
        } else{
            break;
        }
    }    
    res*=-1;
    cout<<res<<'\n';

}
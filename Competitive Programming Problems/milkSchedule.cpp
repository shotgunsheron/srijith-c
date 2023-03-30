#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>cows;
    vector<int>res;
    int n;
    cin>>n;

    int q;
    cin>>q;
    while(n--){
        int x;
        cin>>x;
        cows.push_back(x);
    }
    while (q--){
        int x;
        int cow=0;
        cin>>x;
        int time=0;
        while (time<=x){
            time=time+cows[cow];
            cow=cow+1;
        }
        res.push_back(cow);
    }
    cout<<'\n';
    for (int i=0;i<res.size();i++){
        cout<<res[i]<<'\n';
    }
}
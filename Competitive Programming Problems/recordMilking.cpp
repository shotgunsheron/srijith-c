#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> record;
    vector<int> bessie;

    while(n--){
        int x;
        cin>>x;
        int y;
        cin>>y;

        for (int i=0;i<x;i++){
            record.push_back(y);

        }
    }
    int currMax=0;
    while(m--){
        int x;
        cin>>x;
        int y;
        cin>>y;
        for (int i=0;i<x;i++){
            bessie.push_back(y);
        }
    }
    int res=0;
    for (int i=0;i<100;i++){
        if (bessie[i]>record[i] and bessie[i]-record[i]>currMax){
            currMax=bessie[i]-record[i];
        }
    }
    cout<<currMax<<'\n';
}
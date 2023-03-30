#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> pedalAxle;
    vector<int> gearRatios;
    while(n--){
        int x;
        cin>>x;
        pedalAxle.push_back(x);
    }
    int m;
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        for (int i=0;i<pedalAxle.size();i++){
            if (x%pedalAxle[i]==0){
                gearRatios.push_back(x/pedalAxle[i]);
            } 
        }
    }
    sort(gearRatios.begin(),gearRatios.end());
    int res=0;
    for (int k=gearRatios.size()-1;k>=0;k--){
        if (gearRatios[k]==gearRatios[gearRatios.size()-1]){
            res++;
        }
    }
    cout<<res<<'\n';

}
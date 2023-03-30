#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> differences;
    vector<int>soldiers;
    while(n--){
        int x;
        cin>>x;
        soldiers.push_back(x);
    }
    int minDistance=abs(soldiers[1]-soldiers[0]);
    int minElement=0;
    for (int i=1;i<soldiers.size();i++){
        int x=abs(soldiers[i]-soldiers[i-1]);
        if (x<=minDistance){
            minDistance=x;
            minElement=i-1;
        }
        //cout<<x<<'\n';
    }
    vector<int>res={minElement, minElement+1};
    if (abs(soldiers[soldiers.size()-1]-soldiers[0])<=minDistance){
        res[0]=soldiers.size()-1;
        res[1]=0;
    }
    cout<<res[0]+1<<' '<<res[1]+1<<'\n';
   // cout<<minDistance<<'\n';
}
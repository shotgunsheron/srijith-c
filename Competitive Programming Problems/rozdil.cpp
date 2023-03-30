#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>cities;
    vector<int>citiesX;

    while(n--){
        int x;
        cin>>x;
        cities.push_back(x);
    }
    citiesX=cities;
    sort(cities.begin(),cities.end());
    if (cities[0]==cities[1]){
        cout<<"Still Rozdil"<<'\n';
    } else{
        int res=0;
        for (int i=0;i<cities.size();i++){
            if (citiesX[i]==cities[0]){
                res=i+1;
                break;
            }
        }
        cout<<res<<'\n';
    }
}
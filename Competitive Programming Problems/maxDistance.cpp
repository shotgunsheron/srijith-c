#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> xCoordinates;
    vector<int> yCoordinates;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        xCoordinates.push_back(x);
    }
    
    for (int i=0;i<n;i++){
        int y; cin>>y;
        yCoordinates.push_back(y);
    }
    int res=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            res=max(res,  (xCoordinates[i]-xCoordinates[j])*(xCoordinates[i]-xCoordinates[j])+(yCoordinates[i]-yCoordinates[j])*(yCoordinates[i]-yCoordinates[j]));
        }
    }
    cout<<res<<'\n';
}
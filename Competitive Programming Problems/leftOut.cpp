#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> a;
    for (int i=0;i<n;i++){
        vector<int> tmp;
        for (int j=0;j<n;j++){
            char c; cin>>c;
            if (c=='R'){
                tmp.push_back(1);
            } else{
                tmp.push_back(0);
            }
        }
        a.push_back(tmp);
    }
    //case 1: reference row is the first one
    int badCows=0;
    vector<int> ans;
    for (int i=1;i<n;i++){
        //first normal
        int tempBadCows=0;
        for (int j=0;j<n;j++){
            if (a[0][j]!=a[i][j]){
                tempBadCows++;
            }
        }
        int tempBadCows2=0;

        for (int j=0;j<n;j++){
            if (a[0][j]!=1-a[i][j]){
                tempBadCows2++;
            }
        }
        badCows+=min(tempBadCows,tempBadCows2);
    }
}
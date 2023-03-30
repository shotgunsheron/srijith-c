#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> cows;
    while(n--){
        char a; int b; cin>>a>>b;
        cows.push_back({a,b});
    }
    int res=1001;
    for (int i=0;i<cows.size();i++){
        int tempres=0;
        for (int j=0;j<cows.size();j++){
            if (cows[j][0]=='G'){
                if (cows[j][1]>cows[i][1]){
                    tempres++;
                }
            } else if (cows[j][0]=='L'){
                if (cows[j][1]<cows[i][1]){
                    tempres++;
                }
            }
        }
        res=min(res,tempres);
    }
    cout<<res<<'\n';
}
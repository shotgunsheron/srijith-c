#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    n*=2;
    vector<int> arr;
    while(n--){
        int x; cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());

    int res=10000;
    for (int i=0;i<arr.size();i++){
        for (int j=i+1;j<arr.size();j++){
            vector<int> v;
            for (int k=0;k<arr.size();k++){
                if (k!=i and k!=j){
                    v.push_back(arr[k]);
                }
            }

            int diff=0;
            for (int k=0;k<v.size();k++){
                if (k%2==1){
                    diff+=v[k]-v[k-1];
                }
            }
            res=min(res,diff);
        }
    }
    cout<<res<<'\n';
}
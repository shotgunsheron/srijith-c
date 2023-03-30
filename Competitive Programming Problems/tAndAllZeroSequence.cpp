#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr;
    bool anyZero=false;
    int anyNotZero=0;
    while(n--){
        int x;
        cin>>x;
        if (x==0){
            anyZero=true;
        } else{
            anyNotZero++;
        }
        arr.push_back(x);
    }
    int res=0;
    if (anyZero){
        res=anyNotZero;
    } else{
        sort(arr.begin(),arr.end());
        bool duplicate=false;
        for (int i=0;i<arr.size()-1;i++){
            if (arr[i]==arr[i+1]){
                duplicate=true;
            }
        }
        if (duplicate){
            res=arr.size();
        } else{
            res=anyNotZero+1;
        }
    }
    cout<<res<<'\n';
    }
}
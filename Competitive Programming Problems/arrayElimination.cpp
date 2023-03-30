#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(30,0);

        vector<int> v;
        for (int i=0;i<n;i++){
            int x; cin>>x; v.push_back(x);
            for (int j=0;j<30;j++){
                if ((x&(int)(pow(2,j)))==(int)pow(2,j)){
                    arr[j]++;
                }
            }
        }
        for (int i=1;i<=v.size();i++){
            bool ok=true;
            for (int j=0;j<arr.size();j++){
                if (arr[j]%i){
                    ok=false;
                    break;
                }
            }
            if (ok){
                cout<<i<<' ';
            }
            
        }
        cout<<'\n';
    }
}
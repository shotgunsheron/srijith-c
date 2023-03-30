#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        while(n--){
            int x; cin>>x;
            arr.push_back(x);
        }
        bool odd;
        cout<<arr.size()-1<<'\n';
        if (arr.size()!=1){
            cout<<1<<' '<<arr.size()<<'\n';
        }

        if ((arr[0]+arr[arr.size()-1])%2==1){
            arr[arr.size()-1]=arr[0];
        } else{
            arr[0]=arr[arr.size()-1];
        }

        if (arr[0]%2==1){
            for (int i=1;i<arr.size()-1;i++){
                if (arr[i]%2==0){
                    cout<<1<<' '<<i+1<<'\n';
                } else{
                    cout<<i+1<<' '<<arr.size()<<'\n';
                }
            }
        } else{
            for (int i=1;i<arr.size()-1;i++){
                if (arr[i]%2==1){
                    cout<<1<<' '<<i+1<<'\n';
                } else{
                    cout<<i+1<<' '<<arr.size()<<'\n';
                }
            }        
        }
    }
    
}
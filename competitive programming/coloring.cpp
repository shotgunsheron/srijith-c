#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int n,m,k; cin>>n>>m>>k;
    int count=0;
    for (int i=0;i<m;i++){
        int x; cin>>x;
        if (x==(n+k-1)/k){
            count++;
        } else if (x>=(n+k-1)/k){
            count = 1 << 30;
        }

    }
    if (count>(n-1)%k+1){
        cout<<"NO"<<'\n';
    } else{
        cout<<"YES"<<'\n';
    }
    }

    
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int biggest=0;
    int curr=0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        if (i==0){
            curr+=y;
        } else{
            curr-=x;
            curr+=y;
        }
        if (curr>biggest){
            biggest=curr;
        }
    }

    cout<<biggest<<'\n';
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    for (int i=0;i<n;i++){
        int tempCount=0;
        for (int k=0;k<3;k++){
            int x;
            cin>>x;
            if (x==1){
                tempCount++;
            }
        }
        if (tempCount>=2){
            count++;
        }
    }
    cout<<count<<'\n';
}
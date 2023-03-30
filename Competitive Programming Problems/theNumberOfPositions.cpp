#include <bits/stdc++.h>
using namespace std;

int main(){
    //at least a people in front
    //at most b people behind
    int res=0;
    int n;
    int a;
    int b;
    cin>>n>>a>>b;

    for (int i=a;i<n;i++){
        if ((n-i-1)<=b){
            res++;
        }
    }
    cout<<res<<'\n';
}
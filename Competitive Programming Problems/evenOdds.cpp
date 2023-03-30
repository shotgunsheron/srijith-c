#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    long long k;
    cin>>n>>k;
    long long res=0;
    
    if (k<=(n+1)/2){
        res=k*2-1;
    }else{

        res=(k - (n + 1) / 2) * 2 ;
    }
    //yes
    cout<<res<<'\n';
}
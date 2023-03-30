#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, k, d; cin>>x>>k>>d;
    x=abs(x);
    long long r=x/d;
    if (r>k){
        r=k;
    }
    long long a=x-r*d;
    k=(long long)max((long long)0, k-r);
    if (k%2==0){
        cout<<a<<'\n';
    } else{
        cout<<d-a<<'\n';
    }
    

}
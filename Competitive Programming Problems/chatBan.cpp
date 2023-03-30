#include <bits/stdc++.h>
using namespace std;

long long get(long long x) {
    return x * (long long)1 * (x + 1) / 2;
}


int main(){
    int t; cin>>t;
    while(t--){
    int k; long long x; cin>>k>>x;
    long long l=0;
    long long r=2*k-1;
    long long res=2*k-1;
    bool over=false;
    while(l<=r){
        int mid=(l+r)/2;
        if (mid>=k){
                over = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
        } else{
                over = (get(mid) >= x);
        }
        if (over){
            res=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    cout<<res<<'\n';
    }
    
}
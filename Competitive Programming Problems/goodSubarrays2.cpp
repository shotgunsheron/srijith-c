#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> arr;
        while(n--){
            long long x; cin>>x;
            arr.push_back(x);
        }
        long long x=0;
        long long y=0;
        long long z=1;
        long long ans=0;
        while(y<arr.size()){
            while(x<(long long)arr.size() and z>arr[y]){
                x++;
                z--;
            }
            ans+=(y-x)+1;
            y++;
            z++;
        }
        cout<<ans<<'\n';   
    }
}
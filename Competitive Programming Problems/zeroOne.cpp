#include <bits/stdc++.h>
using namespace std;


int main(){
    long long t; cin>>t;
    while(t--){
    long long n, x, y; cin>>n>>x>>y;
    string a; cin>>a;
    string b; cin>>b;

    long long d=0;
    vector<long long> diff;
    for (long long i=0;i<n;i++){
        if (a[i]!=b[i]){
            d++;
            diff.push_back(i);
        }
    }
    if (d%2!=0){
        cout<<-1<<'\n';
    } else{
        if (d==2 and diff[1]-diff[0]==1){
            cout<<min(x,2*y)<<'\n';            
        } else if (d==2){
            cout<<y<<'\n';
        } else{
            cout<<d/2*y<<'\n';
        }
    }
    }
}
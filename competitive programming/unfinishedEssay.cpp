#include <bits/stdc++.h>
using namespace std;


int main(){
    long long t; cin>>t;
    while(t--){
        long long n,c,q; cin>>n>>c>>q;
        string s; cin>>s;
        vector<vector<long long>> a;
        long long curEnd=s.length();
        for (long long i=0;i<c;i++){
            long long x,y; cin>>x>>y;
            a.push_back({curEnd+1,curEnd+1+y-x,x,y});
            //cout<<curEnd+1<<' '<<curEnd+1+y-x<<' '<<x<<' '<<y<<'\n';
            curEnd+=y-x+1;
            //cout<<curEnd<<'\n';
        }
        while(q--){
            long long i; cin>>i;
            while(i>n){
                for (long long j=0;j<a.size();j++){
                    if (a[j][0]<=i and a[j][1]>=i){
                        i=a[j][2]+i-a[j][0];
                    }
                }
            }
            cout<<s[i-1]<<'\n';
        }
    }


    
}
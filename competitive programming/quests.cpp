#include <bits/stdc++.h>
using namespace std;


long long solve(vector<long long> q, long long k, long long d){
    long long curCoins=0;
    for (long long j=0;j<d;j++){  
        if (j%(k+1)<q.size()){
            curCoins+=q[j%(k+1)];

        }          
    }
    //cout<<curCoins<<'\n';
    return curCoins;
    
        //cout<<k<<' '<<curCoins<<'\n';    
}

int main(){
    long long t; cin>>t;
    while(t--){
    long long n,c,d; cin>>n>>c>>d;
    vector<long long> q(n);
    for (long long i=0;i<n;i++){
        cin>>q[i];
    }
    sort(q.begin(),q.end(),greater<long long>());

        long long l=0; long long r=d+2; 
        long long k=(l+r)/2;

            while(l<=r){
                long long curCoins=solve(q,k,d);
                if (curCoins<c){
                    r=k-1;
                } else if (curCoins>=c){
                    l=k+1;
                }
                k=(l+r)/2;
                //cout<<curCoins<<' '<<k<<'\n';
                
            }
        //cout<<solve(q,13,d)<<'\n';
        if (solve(q,k,d)<c){
            cout<<"Impossible"<<'\n';
        } else if (solve(q,d,d)>=c){
            cout<<"Infinity"<<'\n';
        } else{
            cout<<k<<'\n';
        }
    }
        
    

}
#include <bits/stdc++.h>
using namespace std;


long long sum_of_digit(long long n, long long val)
{
    if (n < 10) {
        val = val + n;
        return val;
    }
    return sum_of_digit(n / 10, (n % 10) + val);
}

int main(){
    long long t; cin>>t;
    while(t--){
        long long n,q; cin>>n>>q;
        vector<long long> a(n);
        vector<long long> counts(n+1,0);
        set<long long> active;
        for (long long i=0;i<n;i++){
            cin>>a[i];
            active.insert(i+1);
        }
        while(q--){
            long long o; cin>>o;
            if (o==2){
                long long x; cin>>x;
                cout<<a[x-1]<<'\n';
            } else{
                long long l,r; cin>>l>>r;
                long long curElement = *active.lower_bound(l);  
                //cout<<curElement<<'\n';
                //break;
                while(curElement<=r){
                    a[curElement-1]=sum_of_digit(a[curElement-1],0);
                    counts[curElement]++;
                    if (counts[curElement]==3){
                        active.erase(curElement);
                    }
                    if (curElement==*active.end()){
                        break;
                    }
                    curElement = *active.lower_bound(curElement+1);
                    
                }
            }
        }
    }
    
}
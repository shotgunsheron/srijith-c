#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n,q; cin>>n>>q;
        vector<long long> pSteps;
        vector<long long> minSteps;
        long long minStep=0;
        long long pValue=0;
        while(n--){
            long long x; cin>>x;
            minStep=max(x,minStep);
            minSteps.push_back(minStep);
            pValue+=x;
            pSteps.push_back(pValue);
        }
        while(q--){
            long long x; cin>>x;
            //use binary search to find first value in minSteps that is greater than x.
            long long r=upper_bound(minSteps.begin(),minSteps.end(),x)-minSteps.begin();

            //r is the position of the first value in minSteps that is greater than x;
            cout<<pSteps[r-1]<<' ';
        }
        cout<<'\n';
    }
}
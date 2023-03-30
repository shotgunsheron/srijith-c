#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n, k; cin>>n>>k;
        vector<long long> pos(n,0);
        vector<long long> neg(n,0);
        for (long long i=0;i<n;i++){
            long long x; cin>>x;
            if (x>=0){
                pos.push_back(x);
            } else{
                neg.push_back(-1*x);
            }
        }
        sort(pos.begin(),pos.end(),greater<long long>()); sort(neg.begin(),neg.end(),greater<long long>());
        vector<long long> distances;
        long long lastElement=pos[0];
        for (long long i=0;i<pos.size();i++){
            //cout<<pos[i]<<'\n';
            //cout<<i<<' '<<pos[i]<<'\n';
            if (i%k==k-1 or i==pos.size()-1){
                //cout<<lastElement<<'\n';
                distances.push_back(lastElement);
                lastElement=pos[i+1];
            }
        }
        lastElement=neg[0];
        for (long long i=0;i<neg.size();i++){
            if (i%k==k-1 or i==neg.size()-1){
                distances.push_back(lastElement);
                lastElement=neg[i+1];
            }
        }
        long long sum=0;
        long long maxDist=0;
        for (long long i=0;i<distances.size();i++){
                sum+=2*distances[i];
                maxDist=max(maxDist,distances[i]);
            
        }
        sum-=maxDist;
        cout<<sum<<'\n';
    }

}
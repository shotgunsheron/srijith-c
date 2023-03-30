#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<long long> endpoints;
    int cur=-1;
    string bessie="bessie";
    for (int i=0;i<s.length();i++){
        if (s[i]==bessie[cur+1]){
            cur++;
            if (cur==0){
                endpoints.push_back(i);
            } else if (cur==5){
                endpoints.push_back(i);
                cur=-1;
            }
        }
    }
    if (endpoints.size()%2!=0){
        endpoints.pop_back();
    }
    endpoints.push_back(endpoints[endpoints.size()-1]+1);
    endpoints.push_back(endpoints[endpoints.size()-2]+1);
    vector<long long> p;
    vector<long long> p2;

    int pSum=0;
    int pSum2=0;
    int cur2=1;
    for (int i=0;i<endpoints.size()-1;i++){
        if (i%2==1){
            pSum+=endpoints[i+2]-endpoints[i];
            pSum2+=(endpoints[i+2]-endpoints[i])*cur2;
            cur2++;
            p.push_back(pSum);
            p2.push_back(pSum2);
        }
    }
    for (int i=0;i<p.size();i++){
        //cout<<p[i]<<'\n';
    }
    long long ans=0;
    int current=-1;
    for (int i=0;i<endpoints.size()-2;i++){
        if (i%2==0){
            int left=0;
            if (i==0){
                left=endpoints[i]+1;
            } else{
                left=endpoints[i]-endpoints[i-2];
            }
            //cout<<left<<'\n';
            if (i!=0){
                ans+=left*(p2[p2.size()-1]-p2[current]-(current+1)*(p[p.size()-1]-p[current]));
            } else{
                ans+=left*(p2[p2.size()-1]-p2[current]);
            }
            //cout<<ans<<'\n';
            current++;
        }
    }
    cout<<ans<<'\n';

}
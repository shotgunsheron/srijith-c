#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c; cin>>a>>b>>c;
    long long m; cin>>m;
    vector<long long> ps;
    vector<long long> usb;
    while(m--){
        long long x; cin>>x; string s; cin>>s;
        if (s=="USB"){
            usb.push_back(x);
        } else{
            ps.push_back(x);
        }
    }
    sort(usb.begin(),usb.end());
    sort(ps.begin(),ps.end());
    long long count=0;
    long long cost=0;
    long long aCount=0;
    long long bCount=0;
    vector<long long> finalArr;

    for (long long i=0;i<usb.size();i++){
        if (i<min(a,(long long)usb.size())){
            count++;
            aCount++;
            cost+=usb[i];
        } else{
            finalArr.push_back(usb[i]);
        }

    }
    for (long long i=0;i<ps.size();i++){
        if (i<min(b,(long long)ps.size())){
            count++;
            bCount++;
            cost+=ps[i];
        } else{
            finalArr.push_back(ps[i]);
        }
    }
    sort(finalArr.begin(),finalArr.end());
    for (long long i=0;i<min((long long)finalArr.size(),c);i++){
        count++;
        cost+=finalArr[i];
    }
    cout<<count<<' '<<cost<<'\n';



}
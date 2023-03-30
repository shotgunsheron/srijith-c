#include <bits/stdc++.h>
#include <initializer_list>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> p, h, s;
    int currP=0, currH=0, currS=0;
    for (int i=0;i<n;i++){

        char x; cin>>x;
        if (x=='P'){
            currP++;
        } else if (x=='H'){
            currH++;
        } else{
            currS++;
        }
        p.push_back(currP);
        h.push_back(currH);
        s.push_back(currS);
    }
    int res=0;
    for (int i=1;i<n;i++){
        int g1P=p[i];
        int g2P=p[n-1]-p[i];
        int g1H=h[i];
        int g2H=h[n-1]-h[i];
        int g1S=s[i];
        int g2S=s[n-1]-s[i];
        res=max(res, max({g1P,g1H,g1S})+max({g2P,g2H,g2S}));
    }
    cout<<res<<'\n';
}
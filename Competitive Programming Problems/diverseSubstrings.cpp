#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int ans=0;
        for (int i=0;i<s.length();i++){
            vector<int> fr(10,0);
            int distinct=0;
            int max_freq=0;
            for (int j=i;j<s.length() and (++fr[s[j]-'0'])<=10;j++){
                max_freq=max(max_freq,fr[s[j]-'0']);
                if (fr[s[j]-'0']==1){
                    distinct++;
                }
                if (distinct>=max_freq){
                    ans++;
                }
            }

        }
        cout<<ans<<'\n';

    }
}
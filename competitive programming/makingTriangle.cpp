#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> l;
    while(n--){
        int x; cin>>x;
        l.push_back(x);
    }
    int ans=0;
    for (int i=0;i<l.size();i++){
        for (int j=i+1;j<l.size();j++){
            for (int k=j+1;k<l.size();k++){
                if (l[i]+l[j]>l[k] and l[i]+l[k]>l[j] and l[j]+l[k]>l[i] and l[i]!=l[j] and l[i]!=l[k] and l[j]!=l[k]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
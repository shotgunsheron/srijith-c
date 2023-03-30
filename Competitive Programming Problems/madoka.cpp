#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a,b;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            a.push_back(x);
        }
        for (int i=0;i<n;i++){
            int x; cin>>x;
            b.push_back(x);
        }

        bool ans=true;
        for (int i=0;i<n;i++){
            if (a[i]>b[i]){
                ans=false;
                break;
            } else{
                if (i!=n-1){
                    if (a[i]!=b[i] and b[i+1]+1<b[i]){
                        ans=false;
                        break;
                    }
                } else{
                    if (a[i]!=b[i] and b[0]+1<b[i]){
                        ans=false;
                        break;
                    }
                }
            }
        }
        cout<<((ans==true) ? "YES" : "NO")<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a;
        int count=0;
        set<int> arr;
        for (int i=0;i<n; i++){
            int x; cin>>x;
            if (x==0 and count<2){
                a.push_back(x);
                arr.insert(x);
                count++;
            } else if (x!=0){
                a.push_back(x);
                arr.insert(x);

            }
        }
        if (a.size()<=6){
            bool ok=true;
            for (int i=0;i<a.size();i++){
                for (int j=i+1;j<a.size();j++){
                    for (int k=j+1;k<a.size();k++){
                        if (arr.count(a[i]+a[j]+a[k])==0){
                            ok=false;
                            break;
                        }
                    }
                }
            }
            cout<<((ok==true) ? "YES":"NO")<<'\n';
        } else{
            cout<<"NO"<<'\n';
        }
    }
}
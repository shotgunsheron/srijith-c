#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> p;
    int num=0;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        num+=x;
        p.push_back(num%n);
    }
    vector<bool> vals(n, false);
    vector<int> firstIndex(n, 0);
    int res=0;
    for (int i=0;i<n;i++){
        int x=p[i];
        if (vals[x]==false){
            vals[x]=true;
            firstIndex[x]=i;
        } else{
            int length = i-firstIndex[x];
            res++;
        }

    }
    cout<<res<<'\n';
}
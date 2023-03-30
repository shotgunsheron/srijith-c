#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> p;
    int num=0;
    while(n--){
        int x; cin>>x;
        num+=x;
        p.push_back(num%7);
    }
    vector<bool> vals = {false,false,false,false,false,false,false};
    vector<int> firstIndex={0,0,0,0,0,0,0};
    int res=0;
    for (int i=0;i<7;i++){
        int x=p[i];
        if (vals[x]==false){
            vals[x]=true;
            firstIndex[x]=i;
        } else{
            int length = i-firstIndex[x];
            res=max(res,length);
        }

    }
    cout<<res<<'\n';
}
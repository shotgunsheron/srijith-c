#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a[200001];
    bool used[200001];
    int n; cin>>n;

    vector<int> arr;
    vector<int> arr2;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
        arr2.push_back(x);
    }
    bool ok=true;
    sort(arr.begin(),arr.end());
    for (int i=0;i<arr.size();i++){
        a[arr[i]]++;
        if (arr[i]<i+1){
            ok=false;
            break;
        } else if (a[arr[i]]>2){
            ok=false;
            break;
        }
    }
    vector<int> p(arr.size(),0);
    vector<int> q(arr.size(),0);

    set<int> inP;
    set<int> inQ;
    set<int> notP;
    set<int> notQ;
    if (ok){
        for (int i=0;i<arr2.size();i++){
            if (!used[arr2[i]]){
                p[i]=arr2[i];
                used[arr2[i]]=true;
            } else{
                q[i]=arr2[i];
            }
        }
        for (int i=0;i<q.size();i++){
            if (q[i]!=0){
                inQ.insert(q[i]);
            }
        }
        for (int i=1;i<=n;i++){
            if (inQ.count(i)==0){
                notQ.insert(i);

            }
        }
        for (int i=0;i<p.size();i++){
            if (p[i]!=0){
                inP.insert(p[i]);
            }
        }
        for (int i=1;i<=n;i++){
            if (inP.count(i)==0){
                notP.insert(i);
            }
        }
        cout<<"YES"<<'\n';
        for (int i=0;i<p.size();i++){
            if (p[i]==0){
                p[i]=*notP.lower_bound(arr2[i]);
                notP.erase(p[i]);
            }
            cout<<p[i]<<' ';

        }
        cout<<'\n';
        for (int i=0;i<q.size();i++){
            if (q[i]==0){
                q[i]=*notQ.lower_bound(arr2[i]);
                notQ.erase(q[i]);
            }
            cout<<q[i]<<' ';
        }
        cout<<'\n';


    } else{
        cout<<"NO"<<'\n';
    }



}

int main(){

    int t; cin>>t;
    while(t--){
        solve();
    }
}
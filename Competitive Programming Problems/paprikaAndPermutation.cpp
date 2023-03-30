#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    vector<int> arr;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    set<int> st;
    vector<int> notIn;
    vector<int> rem;
    for (int i=0;i<n;i++){
        
        if (arr[i]<=n){
            if (st.count(arr[i])==0){
                st.insert(arr[i]);
            } else{
                rem.push_back(arr[i]);
            }

        } else{
            rem.push_back(arr[i]);
        }
    }
    for (int i=1;i<=n;i++){
        if (st.count(i)==0){
            notIn.push_back(i);
        }
    }
    bool yes=true;
    for (int i=0;i<rem.size();i++){
        if (notIn[i]>(rem[i]-1)/2){
            yes=false;
            break;
        }
    }
    if (yes){
        cout<<rem.size()<<'\n';
    } else{
        cout<<-1<<'\n';
    }
    }
}
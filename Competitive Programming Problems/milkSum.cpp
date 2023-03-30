#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}

int main(){
    int n; cin>>n;
    vector<int> arr;
    vector<vector<int>> arr2;
    vector<int> original(n+1);
    vector<int> pos(n+1);
    for (int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
        arr2.push_back({x,i+1});
        original[i+1]=x;
    }
    map<int,int> mp;
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end(),cmp);
    vector<int> p;
    int pSum=0;
    int t=0;
    for (int i=0;i<n;i++){
        pos[arr2[i][1]]=arr2[i][0]*(i+1);
        mp[arr[i]]=i;
        pSum+=arr[i];
        t+=arr[i]*(i+1);
        p.push_back(pSum);
    }
    int q; cin>>q;
    while(q--){
        int i,j; cin>>i>>j;
        //cout<<original[i]<<'\n';
        //cout<<t<<'\n';
        //find pos[j]*j
        int posJ=lower_bound(arr.begin(),arr.end(),j)-arr.begin();
        //cout<<p[mp[original[i]]-1]<<' '<<p[posJ-1]<<'\n';

        int ans=t-pos[i]+(posJ+1)*j;
        if (posJ<=mp[original[i]]){
            ans+=p[mp[original[i]]-1]-p[posJ-1];
        } else{
            ans=t-(p[n-1]-p[mp[original[i]]])+p[n-1]-p[posJ-1]+(posJ)*j-pos[i];

        }
        cout<<ans<<'\n';
    }
    

}
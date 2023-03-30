#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
    long long n; cin>>n;
    vector<long long> arr;
    long long sum=0;
    for (long long i=0;i<n;i++){
        long long x; cin>>x;
        sum+=x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());


    long long m; cin>>m;
    while(m--){
        long long defense; cin>>defense;
        long long attack; cin>>attack;
        long long y=lower_bound(arr.begin(), arr.end(), defense)-arr.begin(); //upper bound
        long long x=y-1;
        //cout<<x<<' '<<y<<'\n';
        long long ans1=max((long long)0,defense-arr[x])+max((long long)0,attack-(sum-arr[x]));
        long long ans2=max((long long)0,defense-arr[y])+max((long long)0,attack-(sum-arr[y]));

        cout<<min(ans1,ans2)<<'\n';
    }
}
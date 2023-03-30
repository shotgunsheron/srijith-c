#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "angry") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    //setIO();
    int n; cin>>n;
    vector<int> arr;
    while(n--){
        int x; cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for (int i=0;i<arr.size();i++){
        int lCounter=1;
        int rCounter=1;
        int res=0;
        int l=i;
        int r=i;
        for (int j=i-1;j>=0;j--){
            int leftbound=i-1;
            for (int k=j-1;k>=0;k--){
                if (arr[j]-arr[k]<=lCounter){
                    res++;
                    leftbound=k;
                }
            }
        }
        
        
        if (res>=ans){
            cout<<i<<'\n';
        }
        ans=max(ans,res);
    }
    
    cout<<ans+1<<'\n';
}
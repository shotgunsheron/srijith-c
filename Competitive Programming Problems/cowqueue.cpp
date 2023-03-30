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

void setIO(string name = "cowqueue") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool cmp(vector<int> a, vector<int>b){
    return (a[0]<b[0]);
}

int main(){
    setIO();
    int n; cin>>n;
    vector<vector<int>> arr;
    while(n--){
        int x,y; cin>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(),arr.end(),cmp);
    int ans=0;
    for (int i=0;i<arr.size();i++){
        if (ans<arr[i][0]){
            ans=arr[i][0]+arr[i][1];
        } else{
            ans=ans+arr[i][1];
        }
    }
    cout<<ans<<'\n';
}
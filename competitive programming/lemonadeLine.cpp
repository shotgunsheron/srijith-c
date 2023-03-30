#include <bits/stdc++.h>
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

void setIO(string name = "lemonade") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
int main(){
    setIO();
    int n; cin>>n;
    vector<int> w;
    while(n--){
        int x; cin>>x;
        w.push_back(x);
    }
    sort(w.begin(),w.end(),greater<int>());
    int ans=0;
    for (int i=0;i<w.size();i++){
        if (w[i]>=i){
            ans++;
        }
    }
    cout<<ans<<'\n';
}
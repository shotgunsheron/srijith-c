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

void setIO(string name = "berries") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int mod;
bool cmp(int a, int b){
    return (a%mod>b%mod);
}

int main(){
    setIO();
    int n, k; cin>>n>>k;
    vector<int> berries;
    int highest=0;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        highest=max(highest, x);
        berries.push_back(x);
    }
    int ans=0;
    for (int b=1;b<=highest;b++){
        int full=0;
        for (int j=0;j<berries.size();j++){
            full+=berries[j]/b;
        }
        if (full<k/2) break;
        
        if (full>=k){
            ans=max(ans,b*(k/2));
            continue;
        } 
        mod=b;
        sort(berries.begin(),berries.end(),cmp);
        int cur=b*(full-k/2);
        for (int j=0;j<berries.size() and j+full<k;j++){
            cur+=berries[j]%b;
        }
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}
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

void setIO(string name = "planting") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


const int MN = 1e5+10;

vector<int> adj_list[MN];
bool visited[MN];


int main(){
    setIO();
    int n, m;
    cin>>n;  m=n-1;

    while(m--){
        int x, y; cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans, int(adj_list[i].size()));
    }
    cout<<ans+1<<'\n';
}
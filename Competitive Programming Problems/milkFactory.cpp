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

void setIO(string name = "factory") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MN = 1e5+10;

vector<int> adj_list[MN];


bool dfs(int node, int target) {
    bool res=false;
    for (auto neighbour: adj_list[node]) {
            if (neighbour==target){
                res=true;
            } else{
                res=dfs(neighbour, target);
            }

        
    }

    return res;
}



int main(){
    setIO();
    int n; cin>>n;

    for (int i=0;i<n-1;i++){
        int x, y; cin>>x>>y;
        adj_list[x].push_back(y);
    }
    bool hit=false;
    for (int i=1;i<=n;i++){
        bool ok=true;
        for (int j=1;j<=n;j++){
            if (j!=i){
                if (dfs(j,i)==false){
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            cout<<i<<'\n';
            hit=true;
            break;
        }
    }
    if (hit==false){
        cout<<-1<<'\n';
    }



}
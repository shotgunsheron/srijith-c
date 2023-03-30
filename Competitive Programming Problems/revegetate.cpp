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

void setIO(string name = "revegetate") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}



const int MN = 1e5+10;

vector<int> adj_list[MN];
int visited[MN];

int main(){
    setIO();
    int n, m;
    cin>>n>>m;
    while(m--){
        int x,y; cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=4;j++){
            bool ok=true;
            for (int k=0;k<adj_list[i].size();k++){
                if (visited[adj_list[i][k]]==j){
                    ok=false;
                    break;
                }
            }
            if (ok){
                visited[i]=j;
                cout<<j;
                break;
            }
        }
    }
    cout<<'\n';
}
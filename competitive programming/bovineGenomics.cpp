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

void setIO(string name = "cownomics") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


int main(){
    setIO();

    int n, m; cin>>n>>m;
    vector<vector<char>> spotted;
    vector<vector<char>> plain;

    for (int i=0;i<n;i++){
        vector<char> temp;
        for (int j=0;j<m;j++){
            char x; cin>>x;
            temp.push_back(x);
        }
        spotted.push_back(temp);
    }
    for (int i=0;i<n;i++){
        vector<char> temp;
        for (int j=0;j<m;j++){
            char x; cin>>x;
            temp.push_back(x);
        }
        plain.push_back(temp);
    }
    int res=m;
    for (int i=0;i<m;i++){
        set<char> s;
        for (int j=0;j<n;j++){
            if (s.count(spotted[j][i])==0){
                s.insert(spotted[j][i]);
            }
        }
        for (int j=0;j<n;j++){
            if (s.count(plain[j][i])==1){
                res--;
                break;
            }
        }        
    }
    cout<<res<<'\n';
}
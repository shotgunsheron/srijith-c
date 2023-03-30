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

void setIO(string name = "circlecross") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO();
    string s; cin>>s;
    vector<vector<int>> indices(26);
    for (int i=0;i<s.length();i++){
        indices[s[i]-'A'].push_back(i);
    }
    int res=0;
    for (int i=0;i<indices.size();i++){
        for (int j=i+1;j<indices.size();j++){
            if (indices[i][0]<indices[j][0] and indices[j][0]<indices[i][1] and indices[i][1]<indices[j][1]){
                res++;
            } else if (indices[j][0]<indices[i][0] and indices[i][0]<indices[j][1] and indices[j][1]<indices[i][1]){
                res++;
            }
        }
    }
    cout<<res<<'\n';
}
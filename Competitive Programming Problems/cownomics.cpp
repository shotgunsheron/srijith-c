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
    int res=0;

    map<int,int> e;
    e['A']=0;
    e['C']=1;
    e['G']=2;
    e['T']=3;
    for (int i=0;i<m;i++){
        for (int j=i+1;j<m;j++){
            for (int k=j+1;k<m;k++){
                bool r=true;
                set<int> s;
                for (int h=0;h<n;h++){
                    int x=16*e[spotted[h][i]]+4*e[spotted[h][j]]+e[spotted[h][k]];
                    if (s.count(x)==0){
                        s.insert(x);
                    }
                }
                for (int h=0;h<n;h++){
                    int x=16*e[plain[h][i]]+4*e[plain[h][j]]+e[plain[h][k]];
                    if (s.count(x)){
                        r=false;
                        break;
                    }
                }             
                if (r){
                    res++;
                }   
            }
        }
    }
    cout<<res<<'\n';
}
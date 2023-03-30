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

void setIO(string name = "helpcross") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main(){
    setIO();
    vector<pair<int,int>> cows;
    multiset<int> chickens;
    int c, n; cin>>c>>n;
    while(c--){
        int x; cin>>x;
        chickens.insert(x);
    }
    for (int i=0;i<n;i++){
        int x, y; cin>>x>>y;
        pair<int,int> p;
        p.first=x; p.second=y;
        cows.push_back(p);
    }
    sort(cows.begin(),cows.end(),cmp);
    int ans=0;
    for (int i=0;i<n;i++){
        auto chosenChicken=chickens.lower_bound(cows[i].first);
        if (chosenChicken!=chickens.end() and *chosenChicken<=cows[i].second){
            ans++;
            chickens.erase(chosenChicken);
        }

    }
    cout<<ans<<'\n';

}
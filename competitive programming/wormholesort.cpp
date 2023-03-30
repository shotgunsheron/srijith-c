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

void setIO(string name = "wormsort") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<int> cows;
vector<vector<int>> wormholes;

bool cmp(vector<int> a, vector<int> b){
    return (a[2]>b[2]);
}



int operation() {
    for (int i=0;i<wormholes.size();i++){
        if (cows[wormholes[i][0]]>cows[wormholes[i][1]]){
            int temp=cows[wormholes[i][0]];
            cows[wormholes[i][0]]=cows[wormholes[i][1]];
            cows[wormholes[i][1]]=temp;
            return wormholes[i][2];
            break;
        }
    }
    return -1;
}


int main(){
    setIO();
    int n, m; cin>>n>>m;


    for (int i=0;i<n;i++){
        int x; cin>>x;
        cows.push_back(x);
    }
    for (int i=0;i<m;i++){
        int x,y,z; cin>>x>>y>>z;
        x--; y--;
        if (x>y){
            int temp=x;
            x=y;
            y=temp;
        }
        wormholes.push_back({x,y,z});
    }
    sort(wormholes.begin(),wormholes.end(),cmp);
    int cur=operation();
    int ans=cur;
    while(cur!=-1){
        ans=min(ans,cur);
        cur=operation();
    }

    cout<<ans<<'\n';
    

}
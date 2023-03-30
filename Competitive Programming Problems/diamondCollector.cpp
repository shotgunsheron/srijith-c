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

void setIO(string name = "diamond") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool cmp(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

int main(){
    //setIO();
    long long n,k; cin>>n>>k;
    vector<long long> a(n);
    for (long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> curArr={0,0};
    for (long long i=0;i<n;i++){
        long long maxIndex=upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
        long long minIndex=lower_bound(a.begin(),a.end(),a[i]-k)-a.begin();
        //cout<<i<<' '<<index<<'\n';
        curArr.push_back(index-i);
    }
    sort(curArr.begin(),curArr.end(),cmp);
    long long ans=0
    cout<<ans<<'\n';
}
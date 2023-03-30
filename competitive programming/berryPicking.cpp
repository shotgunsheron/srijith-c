#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<long long>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (long long) (x).size()

using pi = pair<long long,long long>;
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

bool cmp(int a,int b)
{
	return (a%mod) > (b%mod);
}

int main(){
    setIO();
    long long n,k; cin>>n>>k;
    vector<long long> trees;
    for (long long i=0;i<n;i++){
        long long x; cin>>x; trees.push_back(x);
    }
    long long maxElement=*max_element(trees.begin(), trees.end());
    long long ans=0;
    for (long long i=1;i<=maxElement;i++){
        vector<long long> curTrees=trees;
        long long b=0;
        for (long long j=0;j<trees.size();j++){
            b+=trees[j]/i;
            //trees[j]=trees[j]%i;
            curTrees[j]=curTrees[j]%i;
        }
        if (b>=k){
            ans=max(ans,i*(k/2));
        } else if (b>=k/2){
            long long tmpAns=i*(b-k/2);
            mod=i;
            sort(curTrees.begin(),curTrees.end(),cmp);
            for (long long j=0;j<(k/2-(b-k/2));j++){
                tmpAns+=curTrees[j]%i;
            }
            ans=max(ans,tmpAns);
        } else{
            break;
        }
        
    }
    cout<<ans<<'\n';
}
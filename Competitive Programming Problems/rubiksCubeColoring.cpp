#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin>>k;
    ll othernodes = (1LL<<k) - 2;
    ll ans = power(4,othernodes,INF);
    ans *= 6;
    ans %= INF;
    cout<<ans<<"\n";
}
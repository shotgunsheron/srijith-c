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

void setIO(string name = "cardgame") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
int main(){
    setIO();
    int n; cin>>n;
    vector<int> elsie;
    set<int> elsieSet;
    vector<int> bessie;
    while(n--){
        int x; cin>>x;
        elsie.push_back(x);
        elsieSet.insert(x);
    }
    int N=elsie.size();
    for (int i=1;i<=(int)elsie.size()*2;i++){
        if (elsieSet.count(i)==0){
            bessie.push_back(i);
        }
    }
    
    sort(elsie.begin(), elsie.begin() + N / 2);
    sort(elsie.begin() + N / 2, elsie.end());
    rotate(elsie.begin(), elsie.begin() + N / 2, elsie.end());

    int res = 0;
    for (int i = N / 2, j = N / 2; i < N; i++, j++, res++) {
        while (j < N && bessie[j] < elsie[i]) {
        j++;
        }
        if (j == N) {
        break;
        }
    }
    for (int i = N / 2 - 1, j = N / 2 - 1; i >= 0; i--, j--, res++) {
        while (j >= 0 && bessie[j] > elsie[i]) {
        j--;
        }
        if (j == -1) {
        break;
        }
    }
    cout << res << endl;

}
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

void setIO(string name = "gymnastics") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO();
    int k,n; cin>>k>>n;
    k--;
    vector<int> first;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        first.push_back(x);
    }
    int res=n*(n-1)/2;
    vector<vector<int>> arr;
    while(k--){
        vector<int> temp;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    for (int i=0;i<first.size();i++){

        for (int j=i+1;j<first.size();j++){
            bool flag=false;

            for (int h=0;h<arr.size();h++){
                for (int g=0;g<n;g++){
                    if (arr[h][g]==first[i]){
                        break;
                    } else if (arr[h][g]==first[j]){
                        res--;
                        flag=true;
                        break;
                    }
                }
                if (flag){
                    break;
                }
            }
        }
    }
    cout<<res<<'\n';
}
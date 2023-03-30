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

void setIO(string name = "balancing") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool cmp(vector<int> a, vector<int> b){
    if (a[0]==b[0]){
        return (a[1]<b[1]);
    }
    return (a[0]<b[0]);
}

int main(){
    setIO();
    int n, l; cin>>n>>l;
    vector<vector<int>> arr;
    set<int> o;
    set<int> p;
    vector<int> x;
    vector<int> y;
    for (int i=0;i<n;i++){
        int g,h; cin>>g>>h;
        if (o.count(g)==0){
            o.insert(g);
            x.push_back(g);
        }
        if (p.count(h)==0){
            p.insert(h);
            y.push_back(h);
        }
        arr.push_back({g,h});
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    map<int,int> xCo;
    map<int,int> yCo;
    for (int i=0;i<x.size();i++){
        xCo[x[i]]=2*i+1;
    }
    for (int i=0;i<y.size();i++){
        yCo[y[i]]=2*i+1;
    }
    for (int i=0;i<arr.size();i++){
        arr[i][0]=xCo[arr[i][0]];
        arr[i][1]=yCo[arr[i][1]];
    }
    int res=101;

    for (int i=0;i<=xCo[x[x.size()-1]]+1;i+=2){
        for (int b=0;b<=yCo[y[y.size()-1]]+1;b+=2){  
            int q=0; int w=0; int e=0; int r=0;
            for (int j=0;j<arr.size();j++){
                if (arr[j][0]<i and arr[j][1]>b){
                    q++;
                } else if (arr[j][0]<i and arr[j][1]<b){
                    e++;
                } else if (arr[j][0]>i and arr[j][1]>b){
                    w++;
                } else if (arr[j][0]>i and arr[j][1]<b){
                    r++;
                }
            }
            res=min(res,max(max(q,e),max(w,r)));
        }
    }
    cout<<res<<'\n';

}
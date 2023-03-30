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

void setIO(string name = "tracing") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool cmp(vector<int> a, vector<int> b){
    return (a[0]<b[0]);
}

bool checkStrings(string a, string b){
    bool res=true;
    for (int i=0;i<a.length();i++){
        if (a[i]!=b[i]){
            res=false;
        }
    }
    return res;
}

int main(){
    int n, t; cin>>n>>t;
    string s; cin>>s;
    vector<vector<int>> interactions;
    for (int i=0;i<t;i++){
        int x,y,z; cin>>x>>y>>z;
        interactions.push_back({x,y,z});

    }

    sort(interactions.begin(),interactions.end(),cmp);
    int res1=0;
    int res2=251;
    int res3=0;
    set<int> xs;
    for (int i=0;i<n;i++){ //check all values for patient zero
        if (s[i]=='1'){
            for (int j=0;j<=251;j++){ //check all values for K
                string resString=s;
                vector<int> cows(26,j);
                for (int k=0;k<resString.length();k++){
                    resString[k]='0';
                }
                resString[i]='1';
                for (int k=0;k<interactions.size();k++){//start simulating
                    int x=interactions[k][0];
                    int y=interactions[k][1]-1;
                    int z=interactions[k][2]-1;
                    if (resString[y]=='1' and cows[y]>0){
                        cows[y]--;
                        resString[z]='1';
                    }
                    if (resString[z]=='1' and cows[z]>0){
                        cows[z]--;
                        resString[y]='1';
                    }
                }

                if (checkStrings(s,resString)){
                        res2=min(res2,j);
                        res3=max(res3,j);

                        if (xs.count(i)==0){
                            xs.insert(i);
                            res1++;
                            
                        }
                    }
                
            }
        }
    }
    if (res3==251){
        cout<<res1<<' '<<res2<<" Infinity"<<'\n';
    } else{
        cout<<res1<<' '<<res2<<' '<<res3<<'\n';

    }

}
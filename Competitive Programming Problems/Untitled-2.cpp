#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j)
                a[i][j] = s[j] - '0';
        }
        if (a[0][0] == 1) {
            cout << -1<< '\n';
        } else{
        
        for (int j = m - 1; j >= 0; --j) {
            for (int i = n - 1; i >= 0; --i) {
                if (a[i][j]) {
                    if (i != 0) {
                        cout<<i<<' '<<j+1<<' '<<i+1<<' '<<j+1<<'\n';
                    } else {
                        cout<<i+1<<' '<<j<<' '<<i+1<<' '<<j+1<<'\n';
                    }
                }
            }
        }
        }
    }
}
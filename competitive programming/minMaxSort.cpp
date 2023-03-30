#include <bits/stdc++.h>
using namespace std;


struct cmp {
	bool operator()(const vector<int> &x, const vector<int> &y) const { return x[1] < y[1]; }
};

void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> pos(n+1);
        for (int i=0;i<n;i++){
            cin>>a[i];
            pos[a[i]]=i;
        } //
        int l = (n +1 ) / 2, r = (n + 2) / 2;
        while (l > 0 && (l == r || (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))) {
            --l;
            ++r;
        }
        cout << (n - r + l + 1) / 2 << '\n';
    }
}
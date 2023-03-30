#include <bits/stdc++.h>
 
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
 
int n, m;
char p;
vector<char> dislikes;
 
bool dislikedString(string str) {
	for(auto c: dislikes) {
		if(str.find(c) != string::npos)
			return true;
	}
	return false;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m;
	while(m--) {
		cin >> p;
		dislikes.PB(p);
	}
 
	int val = n;
	while(true) {
		string s = to_string(val);
		if(!dislikedString(s)) break;
		val++;
	}
 
	cout << val << endl;
 
	return 0;
}
// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	for (int testcase = 0; testcase < t; testcase++) {
		string a,b; cin >> a >> b;
		int child[52];
		vector<vector<int>> parent(52,vector<int>());
		for (int i = 0; i < 52; i++) child[i] = -1;
		int ans = 0;
		bool check = true;
		for (int i = 0; i < a.length(); i++) {
			int currCharA = -1; int currCharB = -1;
			if ((int)a.at(i) >= 97) {
				currCharA = (int)a.at(i)-71;
			}
			else {
				currCharA = (int)a.at(i)-65;
			}
			if ((int)b.at(i) >= 97) {
				currCharB = (int)b.at(i)-71;
			}
			else {
				currCharB = (int)b.at(i)-65;
			}
			if (child[currCharA] == -1 && currCharA != currCharB) {
				ans++;
				child[currCharA] = currCharB;
				parent[currCharB].push_back(currCharA);
			}
			else if (child[currCharA] == -1 && currCharA == currCharB) {
				child[currCharA] = currCharB;
				parent[currCharB].push_back(currCharA);
			}
			else if (child[currCharA] != -1 && child[currCharA] != currCharB) {
				check = false;
			}
		}
		if (!check) {cout << -1 << endl; continue;}
		bool cycleAllow = false;
		for (int i = 0; i < 52; i++)
			if (child[i] == -1) cycleAllow = true;
		bool reachable[52][52];
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
				reachable[i][j] = false;
		for (int i = 0; i < 52; i++) {
			int curr = i;
			bool visited[52];
			for (int j = 0; j < 52; j++) visited[j] = false;
			while (child[curr] != -1) {
				if (child[curr] != curr && !visited[child[curr]]) {
					reachable[i][child[curr]] = true;
					visited[child[curr]] = true;
					curr = child[curr];
				}
				else {
					break;
				}
			}
		}
		bool cycleCheck[52]; bool cycleFound[52];
		for (int i = 0; i < 52; i++) {cycleCheck[i] = false;cycleFound[i] = false;}
		int cycles = 0;
		for (int i = 0; i < 52; i++) {
			if (reachable[i][i] && !cycleCheck[i]) {
				bool resolvable = false;
				for (int j = 0; j < 52; j++) {
					if (reachable[i][j]) {
						cycleCheck[j] = true;
						cycleFound[i] = true;
						if (parent[j].size() > 1) resolvable = true;
					}
				}
				if (!resolvable) cycles++;
			}
		}
		for (int i = 0; i < 52; i++) {
			if (parent[i].size() == 0) cycleAllow = true;
		}
		if (cycles > 0 && !cycleAllow) {
			cout << -1 << endl; continue;
		}
		else ans += cycles;
		if (testcase != t-1) cout << ans << endl;
		else cout << ans;
	}
}

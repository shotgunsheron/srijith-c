#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * @author Qi Wang
 * (detemplifying courtesy to Kevin Sheng)
 */
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;
	vector<int> T(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	long long prefix_sum = 0;
	long long ans = 0;
	map<long long, int> sums;
	sums[0] = 1;
    for (int i=0;i<N;i++){
        prefix_sum+=T[i];

        ans+=sums[prefix_sum-X];

        sums[prefix_sum]++;

    }
    cout<<ans<<'\n';
}
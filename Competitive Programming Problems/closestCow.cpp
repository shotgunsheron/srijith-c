#include <bits/stdc++.h>
using namespace std;

int main(){
	int K, M, N;
	cin >> K >> M >> N;
    vector<pair<int, int>> patches(K + M); // patches and Nhoj's cows

	for (int i = 0; i < K; ++i) {
		cin >> patches[i].first >> patches[i].second;
    }
	for (int i = K; i < K + M; ++i) {
		cin >> patches[i].first;
		patches[i].second = -1;
	}
	sort(begin(patches), end(patches));

	vector<uint64_t> increases;
    int last_i = -1;
	uint64_t sum_range = 0;
    for (int i=0;i<(int)patches.size();i++){
        if (patches[i].second==-1){
            if (last_i==-1){ //leftmost
                increases.push_back(sum_range);
            } else{
                uint64_t cur_ans_1 = 0;	 // current sum of window
				uint64_t best_ans_1 = 0; // best sum over all windows
                for (int j=last_i+1, r=last_i;j<i;j++){
                    while(r+1<i and (patches[r+1].first-patches[j].first)*2<patches[i].first-patches[last_i].first){
                        cur_ans_1+=patches[r+1].second;
                        r++;
                    }
                    best_ans_1=max(best_ans_1, cur_ans_1);
                    cur_ans_1-=patches[j].second;
                }
                increases.push_back(best_ans_1);
                increases.push_back(sum_range-best_ans_1);

            }
            last_i=i;
            sum_range=0;
        } else{
            sum_range += patches[i].second;
        }
    }
	increases.push_back(sum_range);
	// sort in decreasing order
	sort(rbegin(increases), rend(increases));
	increases.resize(N);
	uint64_t ans = 0;
	for (auto val : increases) 
		ans += val;
	cout << ans << "\n";
}
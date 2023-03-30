#include <bits/stdc++.h>
using namespace std;


long long countDigit(long long n) {
  return floor(log10(n) + 1);
}
 

long long findMax(multiset<long long> my_set)
{
 
    // Get the maximum element
    long long max_element;
    if (!my_set.empty())
        max_element = *(my_set.rbegin());
 
    // return the maximum element
    return max_element;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> aV;
        vector<long long> bV;
        for (long long i=0;i<n;i++){
            long long x; cin>>x;
            aV.push_back(x);
        }
        for (long long i=0;i<n;i++){
            long long x; cin>>x;
            bV.push_back(x);
        }  

		priority_queue<long long> qa(aV.begin(), aV.end());
		priority_queue<long long> qb(bV.begin(), bV.end());
        
        long long ans=0;  
		while (!qa.empty()){
			if (qa.top() == qb.top()){
				qa.pop();
				qb.pop();
				continue;
			}
			++ans;
			if (qa.top() > qb.top()){
				qa.push(to_string(qa.top()).size());
				qa.pop();
			}
			else{
				qb.push(to_string(qb.top()).size());
				qb.pop();
			}
		}
        cout<<ans<<'\n';
    }
}
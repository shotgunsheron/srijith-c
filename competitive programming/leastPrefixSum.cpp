#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<long long> a;
    vector<long long> p;
    long long pSum = 0;
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a.push_back(x);
      pSum += x;
      p.push_back(pSum);
    }

    long long ans = 0;
    int tempM=p[m-1];
    priority_queue<long long,vector<long long>, greater<long long>> neg;
 
    long long minNum=(1e10+1);
      for(int i=m;i<n;i++){
        if(a[i]<0){
          neg.push(a[i]);
        }
        p[i] = p[i-1]+p[i];
        while(p[i]<p[m-1]){
          p[i]+=2*abs(neg.top());
          ans++;
          neg.pop();
        }
      }
 
    p[m-1]=tempM;

    priority_queue<int> pos;
    for (int i = m - 1; i >= 0; i--) {
      // cout << p[i] << '\n';
 
 
      while (p[i] < p[m - 1]) {
 
        p[m - 1] -= 2 * pos.top();
        pos.pop();
        ans++;
      }
        pos.push(a[i]);
 
 
    }
 
    // cout<<'\n';
    cout << ans << '\n';
  }
}
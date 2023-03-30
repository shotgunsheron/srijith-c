#include <bits/stdc++.h>
using namespace std;


long long bs_sqrt(long long x) {
  long long left = 0, right = 2000000123;
  while (right > left) {
      long long mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long l, r; cin>>l>>r;
        long long lSqrt=bs_sqrt(l);
        long long rSqrt=bs_sqrt(r);
        long long ans=0;
        if (lSqrt==rSqrt){
            for (int i = 0; i < 3; i++) {
                if (l <= lSqrt * (lSqrt + i) && lSqrt * (lSqrt + i) <= r) ans++;
            }
        } else{
            ans=(rSqrt-lSqrt-1)*3+((l%lSqrt==0) ? 1 : 0)+((r%rSqrt==0) ? 1 : 0)+((r>rSqrt*(rSqrt+1)) ? 1 : 0)+((r>rSqrt*(rSqrt)) ? 1 : 0)+((l<lSqrt*(lSqrt+1)) ? 1 : 0)+((l<lSqrt*(lSqrt+2)) ? 1 : 0);
        }

        cout<<ans<<'\n';
    }

}
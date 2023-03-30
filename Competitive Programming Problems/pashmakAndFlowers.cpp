#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}
int main(){
    long long n;
    cin>>n;
    long long n2=n;
    vector<long long>flowers;
    while(n--){
        long long x;
        cin>>x;
        flowers.push_back(x);
    }
    sort(flowers.begin(),flowers.end());
    long long maxDiff=flowers[flowers.size()-1]-flowers[0];
    long long highest=flowers[flowers.size()-1];
    long long lowest=flowers[0];
    long long maximums=0;
    long long minimums=0;

    for (long long i=flowers.size()-1;i>=0;i--){
        if (flowers[i]==highest){
            maximums++;
        } else if (flowers[i]==lowest){
            minimums++;
        }
    }
    long long ways=maximums*minimums;

    if (highest==lowest){
        ways=n2*(n2-1)/2;
    }
    cout<<maxDiff<<' '<<ways<<'\n';
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=INT_MAX*10e9;
    for (long long i=0;i<n;i++){
        vector<long long> b=a;
        b[i]=0;
        long long count=0;
        for (long long j=i+1;j<n;j++){
            if (j==i+1){
                b[j]=a[j];
                count+=1;
            } else{
                long long ops=b[j-1]/a[j]+1;
                count+=ops;
                b[j]=ops*a[j];
            }
        }
        for (long long j=i-1;j>=0;j--){
            if (j==i-1){
                b[j]=-1*a[j];
                count+=1;
            } else{
                long long ops=abs(b[j+1]/a[j])+1;
                count+=ops;
                b[j]=-1*ops*a[j];
            }
        }
        ans=min(ans,count);

    }
    cout<<ans<<'\n';
}
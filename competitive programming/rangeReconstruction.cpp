#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<vector<long long>> r(n,vector<long long>(n,0));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n-i;j++){
            long long x; cin>>x;
            r[i][i+j]=x;
        }
    } 
    vector<long long> ans(n);
    ans[0]=0;

    for (long long i=1;i<n;i++){
        ans[i]=ans[i-1]+r[i-1][i];
        for (long long j=i-1;j>=0;j--){
            long long minNum=1e9+1;
            for (long long k=j;k<i;k++){
                minNum=min(minNum,ans[k]);
            }
            long long maxNum=-1*(1e9+1);

            for (long long k=j;k<=i;k++){
                maxNum=max(maxNum,ans[k]);
            }            
            if (maxNum-minNum!=r[j][i]){
                ans[i]=ans[i-1]-r[i-1][i];
                break;
            }
        }
    }
    for (long long i=0;i<ans.size();i++){
        cout<<ans[i];
        if (i==ans.size()-1){
            cout<<'\n';
        } else{
            cout<<' ';
        }
    }
}
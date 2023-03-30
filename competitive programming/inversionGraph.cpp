#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> b(n+1,0);
        int ceiling=n;
        for (int i=n-1;i>=0;i--){
            if (ceiling>arr[i]){
                b[arr[i]]+=i;
                
                b[ceiling]+=-1*i;
                //cout<<b[arr[i]]<<' '<<b[ceiling]<<'\n';
                ceiling=arr[i];
            }
        }
        vector<int> p(n);
        int pSum=0;
        for(int i=0;i<n;i++){
            pSum+=b[i];
            p[i]=pSum;
            //cout<<p[i]<<' ';
        }
        int curr=arr[0];
        int ans=1;
        int counter=0;
        for (int i=0;i<n;i++){
            //cout<<arr[i]<<' '<<curr<<' '<<counter<<'\n';
            if (arr[i]>curr){
                if (p[curr-1]<i){
                    ans++;
                }
                curr=arr[i];
            }
            if (arr[i]==counter+1){
                counter++;
            }

                
        }
        cout<<ans<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
    long long n,x; cin>>n>>x;
    vector<long long> arr(n);

    for (long long i=0;i<n;i++){
        arr[i]=i+1;
        
    }
    arr[0]=x;
    arr[n-1]=1;
    if (x!=n){
        arr[x-1]=n;

    }

    vector<long long> indices={x-1};
    for (long long i=2;i<n;i++){
        if (i==x){
            long long multiple=2*x;
            while(n%multiple !=0 and multiple<n){
                multiple+=x;
            }
            cout<<i<<' '<<multiple<<'\n';
            if (n%multiple==0 and multiple<n){
                swap(arr[i-1],arr[multiple-1]);
                x=multiple;
            }
        }
    }

    if (n%x==0){
        for (long long i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    } else{
        cout<<-1<<'\n';
    }
}

}
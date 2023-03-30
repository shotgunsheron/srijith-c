#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nT=2*n;
    int lCount=0;
    int rCount=0;
    bool lR=false; //if false, then left. if true, then right
    while (nT--){
        int x;
        cin>>x;
        if (x==1){
            if (lR==false){
                lCount++;
                lR=true;
            } else{
                rCount++;
                lR=false;
            }
        } else{
            if (lR==true){
                lR=false;
            } else{
                lR=true;
            }
        }

    }
    //cout<<lCount<<" "<<rCount<<'\n';
    int res=0;
    if (lCount>n-lCount){
        res+=n-lCount;
    } else if (lCount<n-lCount){
        res+=lCount;
    } else{
        res+=lCount;
    }
    if (rCount>n-rCount){
        res+=n-rCount;
    } else if (n-rCount){
        res+=rCount;
    } else{
        res+=rCount;
    }    
    cout<<res<<'\n';
}
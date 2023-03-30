#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
while(t--){
    int n; cin>>n;
    vector<int> arr;
    int numOfTwos=0;
    while(n--){
        int x; cin>>x;
        int y=x;
        while(y%2==0){
            numOfTwos++;
            if (y%2!=0){
                break;
            } else{
                y/=2;
            }
        }
        arr.push_back(x);
    }
    int minOps=0;
    vector<int> mults;
    for (int i=1;i<arr.size();i+=2){
        int index=i+1;
        int mult=0;
        while(index%2==0){
            mult++;
            if (index%2!=0){
                break;
            } else{
                index/=2;
            }            
        }           
        mults.push_back(mult);

    }
    if (mults.size()>0){
        sort(mults.begin(),mults.end(), greater<int>());
    }
    if (arr.size()==numOfTwos){
        minOps=0;
    } else{
        for (int i=0;i<mults.size();i++){
            if (numOfTwos<arr.size()){
                numOfTwos+=mults[i];
                minOps++;
            } else{
                break;
            }
        }
    }

    if (numOfTwos<arr.size()){
        minOps=-1;
    }
    cout<<minOps<<'\n';
}
}
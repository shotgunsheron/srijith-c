#include <bits/stdc++.h>
using namespace std;



vector<int> command(vector<int> a, int startIndex, int endIndex){
    int num=0;
    if (a[startIndex]>0){
        int minNum=10001;
        for (int i=startIndex; i<endIndex; i++){
            minNum=min(minNum,a[i]);
        }
        for (int i=startIndex; i<endIndex;i++){
            a[i]-=minNum;
        }        
        num=minNum;
    } else{
        int minNum=-10000000;
        for (int i=startIndex; i<endIndex; i++){

            minNum=max(minNum,a[i]);
        }
        for (int i=startIndex; i<endIndex;i++){
            a[i]-=minNum;
        }                
        num=minNum;
    }
    a.push_back(num);
    return a;
}

int main(){
    int n; cin>>n;
    vector<int> a,arr;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for (int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(a[i]-x);
    }

    int sum=1;
    int ans=0;
    while(arr.size()!=0){
        if (arr[arr.size()-1]==0){
            arr.pop_back();
        }
        int startIndex=0;

        if (arr[arr.size()-1]>0){
            int minVal=10001;
            for (int i=arr.size()-1;i>=0;i--) {
                if (arr[i]>0 and arr[arr.size()-1]>0){
                    startIndex=i;
                    minVal=min(arr[i],minVal);
                } else{
                    break;
                }
            }
            for (int i=startIndex;i<arr.size();i++){
                arr[i]-=minVal;
            }
            ans+=minVal;
        } else if (arr[arr.size()-1]<0){
            int maxVal=-100001;
            for (int i=arr.size()-1;i>=0;i--) {
                if (arr[i]<0 and arr[arr.size()-1]<0){
                    startIndex=i;
                    maxVal=max(arr[i],maxVal);
                } else{
                    break;
                }
            }
            for (int i=startIndex;i<arr.size();i++){
                arr[i]-=maxVal;
            }
            ans+=abs(maxVal);            
        }

        
    }

    cout<<ans<<'\n';
}
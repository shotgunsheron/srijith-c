#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int distinct=1;
    bool res=true;
    int nums[1000]={0};
    int sizeVar=arr.size();
    //if (sizeVar%2!=0){
    //    sizeVar++;
    //}
    if (arr.size()>1){
        distinct=0;
        for (int i=0;i<arr.size()-1;i++){
            nums[arr[i]]++;
            if (nums[arr[i]]>(arr.size()+1)/2){
                distinct=0;
                break;
            }
            if (arr[i]!=arr[i+1]){
                distinct+=2;
            } else{
                distinct--;
            }
        }
    }
    //cout<<nums[284]<<'\n';
    //cout<<nums[285]<<'\n';
    if (distinct>0){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
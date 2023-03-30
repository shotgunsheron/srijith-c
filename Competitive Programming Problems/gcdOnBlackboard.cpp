#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> f;
    vector<int> nums;
    
    int pF; cin>>pF;
    f.push_back(pF);
    nums.push_back(pF);
    n--;
    while(n--){
        int x; cin>>x;
        pF=__gcd(pF,x);
        f.push_back(pF);
        nums.push_back(x);
    }
    vector<int> b(nums.size());
    int pB=nums[nums.size()-1];
    b[nums.size()-1]=pB;
    for (int i=nums.size()-2;i>=0;i--){

        pB=__gcd(pB, nums[i]);
        
        b[i]=pB;
    }
    int res;
    for (int i=0;i<nums.size();i++){
        if (i==0){
            res=__gcd(a[0],b[i+1]);
        } 
    }


}
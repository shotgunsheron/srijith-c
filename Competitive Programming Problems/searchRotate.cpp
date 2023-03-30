#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    target=0;
    int l=0;
    int r=nums.size()-1;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if (nums[mid]==target){
            break;
        } else if (nums[mid]>=nums[l]){
            if (target<=nums[mid] and target>=nums[l]){
                r=mid-1;
            } else{
                l=mid+1;
            }
        } else{
            if (target>=nums[mid] and target<=nums[r]){
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
    }
    
}
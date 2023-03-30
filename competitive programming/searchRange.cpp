#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={1};
    int target=0;
    bool res=true;

    if (nums.size()==0){
        res=false;
    } else{
        int l=0;
        int r=nums.size()-1;
        int med=(l+r)/2;
        if ((l+r)%2!=0){
            med=(l+r)/2+1;
        }
        while(med!=target and l!=r){
            if (nums[med]>target){
                r=med-1;
            } else if (nums[med]<target){
                l=med+1;
            } else{
                break;
            }
            med=(l+r)/2;
            if ((l+r)%2!=0){
                med=(l+r)/2+1;
            }
            if (l>=r){
                res=false;
            }

            
        }
        int start=med;
        for (int i=med-1;i>=0;i--){
            if (nums[i]==target){
                start=i;
            } else{
                break;
            }
        }
        int end=med;
        for (int i=med+1;i<nums.size();i++){
            if (nums[i]==target){
                end=i;
            } else{
                break;
            }
        }
        if (res==false){
            start=-1; end=-1;
        }

        cout<<start<<' '<<end<<'\n';
    }
    cout<<-1<<' '<<-1<<'\n';


    
}
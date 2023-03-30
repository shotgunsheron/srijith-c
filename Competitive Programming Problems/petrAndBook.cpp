#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int>days;
    int sumOfDays=0;
    for (int i=0;i<7;i++){
        int x;
        cin>>x;
        days.push_back(x);
        sumOfDays+=x;
    }
    int res;
    if (sumOfDays<n){
        int h=n%sumOfDays;
        if (h!=0){
            for (int k=0;k<7;k++){
                h-=days[k];
                if (h<=0){
                    res=k+1;
                    break;
                }
            }
        } else{
            for (int g=days.size()-1;g>=0;g--){
                if (days[g]!=0){
                    res=g+1;
                    break;
                }
            }
        }

        
    } else{
        int h=n;
        for (int k=0;k<7;k++){
            h-=days[k];
            if (h<=0){
                res=k+1;
                break;
            }
        }

    }
    cout<<res<<'\n';
}
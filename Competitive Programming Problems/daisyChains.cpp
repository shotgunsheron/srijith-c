#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> flowers;
    while(n--){
        int x; cin>>x;
        flowers.push_back(x);
    }
    int res=0;
    for (int i=0;i<flowers.size();i++){
        for (int j=0;j<flowers.size()-i;j++){
            double avg=0;
            for (int k=j;k<=j+i;k++){
                avg+=flowers[k];
            }
            avg/=(i+1);
            for (int k=j;k<=j+i;k++){
                if (flowers[k]==avg){
                    res++;
                    break;
                }
            }            
        }
    }
    cout<<res<<'\n';
}
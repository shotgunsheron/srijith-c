#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>planes;
    vector<int>planescopy;
    while(m--){
        int x;
        cin>>x;
        planes.push_back(x);
    }
    int n2=n;
    int min=0;
    int max=0;
    planescopy=planes;
    while(n--){
        sort(planes.begin(),planes.end());

        for (int i=0;i<planes.size();i++){
            if (planes[i]>0){
                min+=planes[i];
                planes[i]--;
                break;
            }
        }
        
        
    }
    while(n2--){
        sort(planescopy.begin(),planescopy.end(), greater<int>());

        for (int i=0;i<planescopy.size();i++){
            if (planescopy[i]>0){
                max+=planescopy[i];
                planescopy[i]--;
                break;
            }
            
        }

    }

    cout<<max<<' '<<min<<'\n';
}
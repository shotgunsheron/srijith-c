#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>res;
    int n;
    cin>>n;
    if (n%2==0){
        for (int i=1;i<=n;i++){
            res.push_back(i);
        }
        for (int k=0;k<res.size();k+=2){
            int temp=res[k];
            res[k]=res[k+1];
            res[k+1]=temp;
        }
    for (int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    } else{
        cout<<-1<<'\n';
    }
 
        
}
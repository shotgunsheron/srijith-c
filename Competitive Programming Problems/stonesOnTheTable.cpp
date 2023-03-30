#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> stones;
    int n;
    cin>>n;
    while(n--){
        char x;
        cin>>x;
        stones.push_back(x);
    }
    int res=0;
    for (int i=0;i<stones.size()-1;i++){
        if (stones[i]==stones[i+1]){
            res++;
        }
    }
    cout<<res<<'\n';    
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>horseShoes;
    int e=4;
    while(e--){
        int x;
        cin>>x;
        horseShoes.push_back(x);
    }
    int res=0;
    for (int i=0;i<horseShoes.size();i++){
        for (int k=0;k<horseShoes.size();k++){
            if (k!=i){
                if (horseShoes[i]==horseShoes[k] and horseShoes[i]!=-1){
                    horseShoes[i]=-1;
                    res++;
                }
            }
        }
    }
    cout<<res<<'\n';
}
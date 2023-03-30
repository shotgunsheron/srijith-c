#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int n,m,k; cin>>n>>m>>k;
    vector<int> active(k+1,false);
    vector<int> cards;

    for (int i=0;i<k;i++){
        int x; cin>>x;
        cards.push_back(x);
    }
    int numActive=1;
    int curIndex=0;
    bool ans=true;
    
    for (int i=k;i>=1;i--){

        if (!active[i]){
            while(cards[curIndex]!=i){
                active[cards[curIndex]]=true;
                curIndex++;
                numActive++;
            }
            active[i]=true;
        }
        //numActive is equal to the number of currently active cards
        if (numActive<=n*m-3){
            numActive--;
            active[i]=true;
        } else{
            ans=false;
            break;
        }
    }
    if (ans){
        cout<<"YA"<<'\n';
    } else{
        cout<<"TIDAK"<<'\n';
    }
    }
}
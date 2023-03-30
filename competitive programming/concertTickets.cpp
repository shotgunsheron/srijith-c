#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    multiset<int> tickets;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        tickets.insert(x);
    }
    int ans=0;
    bool empty=false;
    while(m--){
        int customer; cin>>customer;
        if (!empty){
            auto index=tickets.upper_bound(customer);
            if (index!=tickets.begin()){
                index--;

            }
            
            int closest=*(index);
            if (closest<=customer){
                cout<<closest<<'\n';
                tickets.erase(index);
                if (tickets.empty()){
                    empty=true;
                }
            } else{
                cout<<-1<<'\n';
            }
        } else{
            cout<<-1<<'\n';
        }
    }
}
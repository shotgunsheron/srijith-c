#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int m; cin>>m;
        vector<int> tree;

        bool ok=true;
        for (int i=0;i<m;i++){
            int x; cin>>x;
            tree.push_back(x);
        }
        int ans=0;
        while(m>1){
            vector<int> tempTree;
            
            for (int i=0;i<tree.size()-1;i+=2){
                if (abs(tree[i]-tree[i+1])!=1){
                    ok=false;
                    break;
                } else{
                    if (tree[i]>tree[i+1]){
                        tree[i]--;
                        tree[i+1]++;
                        ans++;
                    }
                    tempTree.push_back(max(tree[i],tree[i+1])/2);
                    //cout<<max(tree[i],tree[i+1])/2<<' ';
                }
            }
            //cout<<'\n';
            if (ok==false){
                break;
            }
            tree=tempTree;
            tempTree.clear();
            m/=2;

        }
        if (ok==false){
            cout<<-1<<'\n';
        } else{
            cout<<ans<<'\n';
        }
    }
}
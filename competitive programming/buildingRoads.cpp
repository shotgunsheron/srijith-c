#include <bits/stdc++.h>

using namespace std;


const int MN = 1e5+10;

vector<int> adj_list[MN];
bool visited[MN];

int dfs(int node){
    int visCount=1;
    visited[node]=true;
    for (auto neighbour: adj_list[node]) {
        if (!visited[neighbour]) {
            visCount += dfs(neighbour);
        }
    }
    return visCount;
}


int main(){
    int n, m;
    cin>>n>>m;
    while(m--){
        int x, y; cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    int count=0;
    vector<int> reps;
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            reps.push_back(i);
            dfs(i);
            count++;
        }
    }
    
    cout<<count-1<<'\n';
    for (int i=0;i<reps.size()-1;i++){
        cout<<reps[i]<<' '<<reps[i+1]<<'\n';
    }

}
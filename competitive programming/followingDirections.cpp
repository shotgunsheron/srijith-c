#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>> graph,vector<vector<int>>& pathIndex,int curPathIndex,vector<int> & paths) {
    
    paths[pathIndex[i][j]]--;
    pathIndex[i][j]=curPathIndex;
    paths[curPathIndex]++;
    if (i!=0){
        if (graph[i-1][j]==0){
            dfs(i-1,j,graph,pathIndex,curPathIndex,paths);
        }
    }
    if (j!=0){
        if (graph[i][j-1]==1){
            dfs(i,j-1,graph,pathIndex,curPathIndex,paths);
        }
    }
}

int main(){
    int n; cin>>n;
    vector<vector<int>> graph(n,vector<int>(n));
    vector<vector<int>> pathIndex(n,vector<int>(n,2*n));
    vector<int> paths(2*n+1,0);

    vector<int> pathCosts(2*n);

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c; cin>>c;
            if (c=='R'){
                graph[i][j]=1;
            } else{
                graph[i][j]=0;
            }
        }
        int x; cin>>x;

        pathCosts[i]=x;
    }
    for (int j=0;j<n;j++){
        int x; cin>>x;
        pathCosts[j+n]=x;
    }
    for (int i=0;i<n;i++){
        if (graph[i][n-1]==1) dfs(i,n-1,graph,pathIndex,i,paths);
    }
    for (int i=0;i<n;i++){
        if (graph[n-1][i]==0) dfs(n-1,i,graph,pathIndex,i+n,paths);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //cout<<pathIndex[i][j]<<' ';
        }
        //cout<<'\n';
    }    
    for (int i=0;i<paths.size()-1;i++){
        //cout<<paths[i]<<'\n';
    }
    int ans2=0;
    for (int i=0;i<paths.size()-1;i++){
         ans2+=pathCosts[i]*paths[i];
    }
    cout<<ans2<<'\n';
    int q; cin>>q;
    while(q--){
        int i; cin>>i; i--;
        int j; cin>>j; j--;
        //cout<<graph[i][j]<<'\n';
        if (graph[i][j]==1){
            //now go down
            if (i==n-1 and j==n-1){
                dfs(i,j,graph,pathIndex,2*n-1,paths);
            } else if (i==n-1 and j!=n-1){
                dfs(i,j,graph,pathIndex,j+n,paths);
            } else{
                dfs(i,j,graph,pathIndex,pathIndex[i+1][j],paths);
            }
            graph[i][j]=0;
        } else {
            if (i==n-1 and j==n-1){
                dfs(i,j,graph,pathIndex,n-1,paths);
            } else if (i!=n-1 and j==n-1){
                dfs(i,j,graph,pathIndex,i,paths);
            } else{
                dfs(i,j,graph,pathIndex,pathIndex[i][j+1],paths);
            }
            graph[i][j]=1;
        }
        int ans=0;
        for (int i=0;i<paths.size()-1;i++){
            ans+=pathCosts[i]*paths[i];
        }
        cout<<ans<<'\n';
    }


}
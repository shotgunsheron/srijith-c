#include <bits/stdc++.h>
using namespace std;



int detect_cycles(vector<vector<int>> graph, vector<bool> & visited, int node, int minElement, int startElement){
    if (visited[node]){
        if (node==startElement){
            return minElement;            
        }
    }
    visited[node]=true;
    minElement=min(minElement,graph[node][1]);
    return detect_cycles(graph,visited,graph[node][0],minElement, startElement);
    
}


int main(){
    int n; cin>>n;
    vector<vector<int>> graph(n+1,vector<int>(2));
    vector<bool> visited(n+1);

    for (int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        graph[i]={x,y};
    }
    cout<<detect_cycles(graph,visited, 1,graph[1][1],1)<<'\n';


}   
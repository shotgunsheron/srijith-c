#include <bits/stdc++.h>
using namespace std;




void dfs(long long node, vector<long long> & adj, vector<bool> & visited, vector<long long> & cur){

        if (!visited[adj[node]]){
            visited[adj[node]]=true;
            cur.push_back(adj[node]);
            dfs(adj[node],adj,visited,cur);        
        } else{
            visited[adj[node]]=true;
            cur.push_back(adj[node]);
        }
    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    long long n; cin>>n;
    vector<long long> adj(n+1);
    vector<long long> v(n+1);
    vector<bool> visited(n+1,false);
    for (long long i=1;i<=n;i++){
        long long x; long long y; cin>>x; cin>>y;
        adj[i]=x;
        v[i]=y;
        
    }
    for (long long i=1;i<=n;i++){
        if (!visited[i]){
            vector<long long> vec={i};
            dfs(i,adj,visited,vec);
            visited[i]=true;


                bool flag=false;
                vector<int> cycle;
                for (long long i=0;i<vec.size()-1;i++){
                    if (vec[i]==vec[vec.size()-1]){
                        flag=true;
                    }
                    if (flag){
                        cycle.push_back(vec[i]);
                    }

                }
                if (flag){
                    for (int i=0;i<cycle.size();i++){ //This is the cycle
                        cout<<cycle[i]<<' ';
                    }
                    cout<<'\n';
                }

        }
    }

}    
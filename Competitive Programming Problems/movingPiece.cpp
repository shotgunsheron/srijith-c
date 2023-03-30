#include <bits/stdc++.h>
using namespace std;




vector<vector<long long>> adj_list(5001);
vector<bool> visited(5001, false);

vector<vector<long long>> cycles;
void dfs(long long node, vector<long long> & cycle) {
    //long long visCount = 1;
    visited[node] = true;
    for (auto neighbour: adj_list[node]) {
        if (!visited[neighbour]) {
            cycle.push_back(neighbour);
            //visCount += dfs(neighbour);
            dfs(neighbour,cycle);
        }
    }
}

constexpr long long TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
constexpr long long INF = TEN(18);


int main(){
    long long n, k; cin>>n>>k;    
    vector<long long> p;
    vector<long long> c(n+1);
    for (long long i=1;i<=n;i++){
        long long x; cin>>x;
        p.push_back(x);
        adj_list[i].push_back(x);
    }
    for (long long i=1;i<=n;i++){
        long long x; cin>>x;
        c[i]=x;
    }
    for (long long i=1;i<=n;i++){
 
        if(!visited[i]){
            vector<long long> cycle;
            cycle.push_back(i);
            dfs(i,cycle);
            cycles.push_back(cycle);

        }
    
    }
    long long ans=-INF;
    for (long long i=0;i<cycles.size();i++){
        vector<long long> cycle=cycles[i];
        long long total=0;
        for (long long j=0;j<cycle.size();j++){
            long long node=cycle[j];
            total+=c[node];
        }
        if (total<=0){
            for (long long j=0;j<cycle.size();j++){
                long long node=cycle[j];
                long long pSum=0;
                long long length=min(k,(long long)cycle.size());
                for (long long h=j+1;h<=length+j;h++){
                    pSum+=c[cycle[h%((long long)cycle.size())]];
                    ans=max(ans,pSum);
                }
            }            
        } else{
            for (long long j=0;j<cycle.size();j++){
                long long node=cycle[j];
                long long numCycles=(k-1)/(long long)cycle.size();
                long long remainder=k-numCycles*(long long)cycle.size()+1;
                remainder=max(remainder,(long long)0);
                long long curAns=total-c[node]+(numCycles-1)*total;
                long long pSum=curAns;

                for (long long h=j;h<j+remainder;h++){
                    pSum+=c[cycle[h%((long long)cycle.size())]];
                    ans=max(ans,pSum);
                }
                
            }
        }
    }
    cout<<ans<<'\n';

}
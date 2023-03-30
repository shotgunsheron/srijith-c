#include <bits/stdc++.h>
using namespace std;

int N;
 
vector<vector<int>> more;
vector<vector<int>> lessV;
vector<vector<int>> cows;

void find() {
    for (int v=0;v<N;v++){
        for (int i=0;i<N;i++){
            more[v][i+1]=more[v][i]+((cows[i][1]>cows[v][1])?1:0);
            lessV[v][i+1]=lessV[v][i]+((cows[i][1]<cows[v][1])?1:0);
        }
    }
}

int main(){
    cin >>N;
    cows.resize(N, vector<int>(2));
    more.resize(N, vector<int>(N));
    lessV.resize(N, vector<int>(N));
    
    for (int i=0;i<N; i++){
        cin>>cows[i][0]>>cows[i][1];
    }
    sort(cows.begin(),cows.end());
    find();
    int ans=0;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            ans++;
            int a,b;
            if (cows[i][1]<cows[j][1]){
                b=more[j][j]-more[j][i];
                a=lessV[i][j]-lessV[i][i];
            } else{
                a=more[i][j]-more[i][i];
                b=lessV[j][j]-lessV[j][i];
            }
            ans+=a+b+a*b;
        }
    }
    cout<<ans+N+1<<'\n';
}
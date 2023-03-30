#include <bits/stdc++.h>
using namespace std;


int ans=0;


int solve(int v){
    cout<<v<<'\n';
    if (v==0){
        cout<<' ' <<ans<<'\n';
        return 0;
    }
    ans+=min(solve((v+1)%32768), solve((2*v)%32768))+1;
    return ans;
}

int main(){
    cout<<solve(32764)<<'\n';

}
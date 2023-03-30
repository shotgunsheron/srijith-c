#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    int res=0;
    for (int a=0;a*a<=n;a++){
        for (int b=0;b*b<=m;b++){
            if (a*a+b==n and a+b*b==m){
                res++;
            }
        }
    }
    cout<<res<<'\n';
}
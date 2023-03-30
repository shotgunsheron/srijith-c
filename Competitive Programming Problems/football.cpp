#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a=0;
    int b=0;
    cin>>n;
    string aTeam;
    cin>>aTeam;
    a++;
    if(n==1){
        cout<<aTeam<<'\n';
    } else{
    string bTeam;
    n-=1;
    while(n--){
        string x;
        cin>>x;
        if (x==aTeam){
            a++;
        } else{
            b++;
            bTeam=x;
        }
        
    }
    if (a>b){
        cout<<aTeam<<'\n';
    } else{
        cout<<bTeam<<'\n';
    }
    }
}
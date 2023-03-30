#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    if (n==1){
        cout<<3<<'\n';
    } else{
        n--;
        int tmpN=n;
        while(tmpN%3!=0){
            tmpN++;
        }
        int c=tmpN/3;
        int a=5+4*(c-1);
        if (n%3==1){
            cout<<a<<'\n';
        } else if (n%3==2){
            cout<<a+2<<'\n';
        } else{
            cout<<a+3<<'\n';
        }
    }

}
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    //n++;
    for (int i=0;i<=n;i++){
        int x=2*(n-i);
        for (int h=0;h<x;h++){
            cout<<' ';
        }
        int lastK=0;
        for (int k=0;k<=i;k++){
            cout<<k;
            if (i>0){
                cout<<' ';
            }
            lastK=k;
        }
        for (int j=lastK-1;j>=0;j--){
            cout<<j;
            if (j>0 and i>0){
                cout<<' ';
            }
        }
        cout<<'\n';
    }
    for (int i=n-1;i>=0;i--){
        int x=2*(n-i);
        for (int h=0;h<x;h++){
            cout<<' ';
        }
        int lastK=0;
        for (int k=0;k<=i;k++){
            cout<<k;
            if (i>0){
                cout<<' ';
            }
            lastK=k;
        }
        for (int j=lastK-1;j>=0;j--){
            cout<<j;
            if (j>0 and i>0){
                cout<<' ';
            }
        }
        cout<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;


int main(){
    int res=0;

    for (int i=1;i<=1000;i++){
        if (i%7+i%11+i%13==7){
            res++;
        }
    }
    cout<<res<<'\n';
}
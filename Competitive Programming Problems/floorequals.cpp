#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0;
    for (double i=1;i<=420;i++){
        if (floor(float(x/21))==floor(float(x/20))){
            x++;
        }
    }
    cout<<x<<'\n';
}

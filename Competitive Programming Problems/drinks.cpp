#include <bits/stdc++.h>
using namespace std;

int main(){
    float avg=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        avg+=x;
    }
    avg/=n;
    cout<<avg<<'\n';
}
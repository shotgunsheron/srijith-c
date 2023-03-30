#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q; cin>>n>>q;
    stack<int> stack;
    int maxElement=0;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        if (x>maxElement){
            maxElement=x;
        }
        stack.push(x);
    }
    for (int i=1;i<=n;i++){

    }
    
}
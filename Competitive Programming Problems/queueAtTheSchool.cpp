#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string children;

    int t;
    cin>>t;
    while(n--){
        char x;
        cin>>x;
        children+=x;
    }
    int f=children.length();
    while(t--){
        int i=0;
        while(f--){
            if (children[i]=='B' and children[i+1]=='G'){
                children[i]='G';
                children[i+1]='B';
                i+=2;
            } else{
                i++;
            }
        }
        f=children.length();
    }
    cout<<children<<'\n';
}
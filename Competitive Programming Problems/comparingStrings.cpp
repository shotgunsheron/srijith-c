#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    string y;
    cin>>x>>y;
    vector<int> letters = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int delta=0;
    for (int i=0;i<x.length();i++){
        letters[x[i]-'a']++;
    }
    for (int i=0;i<y.length();i++){
        letters[y[i]-'a']--;
        if (y[i]!=x[i]){
            delta++;
        }
    }
    sort(letters.begin(),letters.end());
    if (letters[0]==0 and letters[25]==0 and delta<=2){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
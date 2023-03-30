#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int curMax=1;
    int cur=1;
    for (int i=1;i<s.length();i++){
        if (s[i]==s[i-1]){
            cur++;
            curMax=max(curMax,cur);
        } else{
            cur=1;
        }
    }

    curMax=max(curMax,cur);
    cout<<curMax<<'\n';
}
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<string>abbrs;
    while(n--){
        string s;
        cin>>s;
        if (s.length()>10){
            string x=s[0]+to_string(s.length()-2)+s[s.length()-1];
            abbrs.push_back(x);
        } else{
            abbrs.push_back(s);
        }
    }
    for (int i=0;i<abbrs.size();i++){
        cout<<abbrs[i]<<'\n';
    }
    
}
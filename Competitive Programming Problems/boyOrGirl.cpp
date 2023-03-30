#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>letters={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s;
    cin>>s;
    int distinctChars=0;
    for (int i=0;i<s.length();i++){
        letters[s[i]-'a']++;
    }
    for (int k=0;k<letters.size();k++){
        if (letters[k]>=1){
            distinctChars++;
        }
    }
    if (distinctChars%2==0){
        cout<<"CHAT WITH HER!"<<'\n';
    } else{
        cout<<"IGNORE HIM!"<<'\n';
    }
}
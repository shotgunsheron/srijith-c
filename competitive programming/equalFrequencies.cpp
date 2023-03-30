#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> freq(26,0);
    for (int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }
    for (int k=1;k<=26;k++){
        if (n%k==0){
            for (int i=0;i<26;i++){
                
            }
        }
    }
}

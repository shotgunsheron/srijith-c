#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long ans=s.length();
    for (int i=0;i<s.length()-1;i++){
        if (s[i]=='0' and s[i+1]=='0'){
            ans--;
            i++;
        }
    }
    cout<<ans<<'\n';
}
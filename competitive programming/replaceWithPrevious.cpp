#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        char maxChar='a';

        for (int i=0;i<n;i++){
            if (s[i]>maxChar){
                if (s[i]-'a'>k){
                    k-=maxChar-'a';
                    int to = s[i] - k;
                    for (char c = s[i]; c > to; c--) {
                        for (char &e:s) if (e == c) {
                            e = char(c-1);
                        }
                    }
                    break;
                } else{
                    maxChar=max(maxChar,s[i]);
                }
            }
        }
        for (char &e:s) if (e <= maxChar) {
            e = 'a';
        }
        cout <<s<<'\n';
    }

}
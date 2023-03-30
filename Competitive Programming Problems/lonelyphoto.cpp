#include <bits/stdc++.h>
using namespace std;


bool checkStrings(string a, string b){
    bool res=true;
    for (long long i=0;i<a.length();i++){
        if (a[i]!=b[i]){
            res=false;
            break;
        }
    }
    return res;
}

int main(){
    long long n; cin>>n;
    string s; cin>>s;
    long long ans=0;
    for (long long i=0;i<s.length();i++){
        bool x=false;
        if ( i<s.length()-2){
            if (s[i+1]!=s[i] and s[i+2]!=s[i]){
                x=true;
            }
        } if (i>=1 and i<s.length()-1){
            if (s[i-1]!=s[i] and s[i+1]!=s[i]){
                x=true;
            }
        } if (i>=2){
            if (s[i-1]!=s[i] and s[i-2]!=s[i]){
                x=true;
            }
        }
        if (x){
            long long left=0;
            for (long long j=i-1;j>=0;j--){
                if (s[j]!=s[i]){
                    left++;
                } else{
                    break;
                }
            }
            long long right=0;
            for (long long j=i+1;j<s.length();j++){
                if (s[j]!=s[i]){
                    right++;
                } else{
                    break;
                }
            }
            ans+=(left+1)*(right+1)-3;
        }

    }
    cout<<ans<<'\n';
}
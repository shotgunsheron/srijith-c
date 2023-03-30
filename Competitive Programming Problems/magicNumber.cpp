#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    string s=to_string(x);
    //cout<<s<<'\n';
    bool res=true;
    int i=0;
    while(res==true){
        if (s[i]=='1'){
            if (s[i+1]=='4'){
                i++;
                if (s[i+1]=='4'){
                    i++;
                    
                }
            }
        } else{
            res=false;
        }
        if (i==s.length()-1){
            break;
        }
        i++;
    }
    if (res==true){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }
}
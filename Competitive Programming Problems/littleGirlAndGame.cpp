#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k=0;
    for (int i=0;i<s.length();i++){

        if (s[i]!=-1){
            int x=count(s.begin(),s.end(), s[i]);
            if (x%2!=0){
                k+=x;
            }
        for (int k=i;k<s.length();k++){
            if (s[k]==s[i]){
                s[k]==-1;
            }
        }
        }
    }
    if (k==0 or k==1){
        cout<<"First"<<'\n';
    } else if (k%2==0){
        cout<<"Second"<<'\n';
    } else if (k%2!=0){
        cout<<"First"<<'\n';
    }
}
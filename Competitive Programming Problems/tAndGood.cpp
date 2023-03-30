#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int currVal=s[0];
    string tempStr="";
    tempStr+=s[0];
    int res=0;
    for (int i=1;i<s.length();i++){
        if (s[i]==currVal){
            tempStr+=s[i];
        } else{
            if (tempStr.length()%2!=0){
                tempStr+=currVal;
                res++;
                //cout<<tempStr<<'\n';
                //cout<<i<<'\n';
            } else{
                tempStr="";
                tempStr+=s[i];
                currVal=s[i];
            }
        }
    }
    //cout<<res<<'\n';
    int resT;
    if (res!=0){
        resT=s.length()-(s.length()-s.length()%res)+1;

    } else{
        int count=0;
        int currValT=s[0];
        for (int k=1;k<s.length();k++){
            if (s[k]!=currValT){
                count++;
            }
        }
        resT=count+1;
    }
    cout<<res<<' '<<resT<<'\n';
}
}
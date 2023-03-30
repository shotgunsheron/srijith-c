#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    vector<string>words;
    string tempstr="";
    
    for (int i=0;i<s.length();i++){
        if (s.length()-1-i>=2){

            if (s[i]=='W' and s[i+1]=='U' and s[i+2]=='B'){
                i=i+2;  
                if (tempstr!=""){
                    words.push_back(tempstr);

                }
                tempstr="";
            } else{
                tempstr+=s[i];
            }
        } else{
            tempstr+=s[i];
            if (i+1<s.length()){
                tempstr+=s[i+1];

            }
            words.push_back(tempstr);
            i=s.length();
        }
    }
    for (int k=0;k<words.size();k++){
        cout<<words[k]<<' ';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string firstLine;
    string secondLine;
    getline(cin, firstLine);
    getline(cin, secondLine);
    vector<int>v={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int>v2={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool res=true;
    for (int i=0;i<firstLine.length();i++){
        if (firstLine[i]!=' '){
            v[firstLine[i]-'A']++;
        }
    }

    for (int i=0;i<secondLine.length();i++){
        if (secondLine[i]!=' '){
            v2[secondLine[i]-'A']++;
        }
        if (v2[secondLine[i]-'A']>v[secondLine[i]-'A']){
            res=false;
            break;
        }
    }

    if (res){
        cout<<"YES"<<'\n';
    } else{
        cout<<"NO"<<'\n';
    }


}
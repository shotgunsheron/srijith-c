#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> letters={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++){
        letters[s[i]-'a']++;
    }
    string res="";
    bool impossible=false;
    for (int j=0;j<letters.size();j++){
        if (letters[j]%k==0){
            for (int h=0;h<letters[j]/k;h++){
                res+=char(j+'a');
            }
        } else{
            impossible=true;
        }
    }
    if (impossible){
        cout<<-1<<'\n';
    } else{
        for (int g=0;g<k;g++){
            cout<<res;
        }
        cout<<'\n';
    }
}
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main(){
    string s;
    cin>>s;
    int upper=0;

    int lower=0;
    vector<int>upperIndexes;
    vector<int>lowerIndexes;
    for (int i=0;i<s.length();i++){
        if (isupper(s[i])){
            upper++;
            upperIndexes.push_back(i);
        } else if (islower(s[i])){
            lower++;
            lowerIndexes.push_back(i);
        }
    }
    if (upper>lower){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else{
        transform(s.begin(), s.end(), s.begin(), ::tolower);

    }
    cout<<s<<'\n';
}
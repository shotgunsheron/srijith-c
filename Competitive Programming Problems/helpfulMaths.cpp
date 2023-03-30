#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    //cout<<s<<'\n';
    vector<int> intNums;

    for (int i=0;i<s.length();i++){
        if (i%2==0){
            //cout<<s[i]-'0'<<'\n';
            intNums.push_back(s[i]-'0');

        }
    }

    sort(intNums.begin(),intNums.end());
    for (int h=0;h<intNums.size();h++){
        if (h!=intNums.size()-1){
            cout<<intNums[h]<<'+';
        } else{
            cout<<intNums[h]<<'\n';
        }
    }
}
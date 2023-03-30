#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(){

    string s; cin>>s;
    vector<int> stck; 
    vector<int> templateVc ((int)s.size(),0);
    vector<vector<int>> prefix_sum (26, templateVc);
    for (int i=0;i<(int)s.size();i++){
        if (i!=0){
            for (int j=0;j<26;j++){
                prefix_sum[j][i]=prefix_sum[j][i-1];
            }
        }

        if (s[i]!='(' and s[i]!=')'){
            if (i==0){
                prefix_sum[s[i]-'a'][i]=1;
            } else{
                prefix_sum[s[i]-'a'][i]=prefix_sum[s[i]-'a'][i-1]+1;
            }
        }
    }
    set<int> container;
    bool res=true;
    for (int i=0;i<(int)s.size();i++){
        if (s[i]!=')' and s[i]!='('){
            if (container.count(s[i]-'a')>0){
                res=false;
                break;
            } else{
                container.insert(s[i]-'a');
            }
        } else if (s[i]==')'){
            int j=stck[stck.size()-1];
            stck.pop_back();
            for (int k=0;k<26;k++){
                if (prefix_sum[k][i]!=prefix_sum[k][j]){
                    container.erase(k);
                }
            }
        }  else if (s[i]=='('){
            stck.push_back(i);
        }
    }
    if (res){
        cout<<"Yes"<<'\n';
    } else{
        cout<<"No"<<'\n';
    }
}
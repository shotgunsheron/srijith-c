#include <bits/stdc++.h>
using namespace std;


int x,y;
bool cmp(string a, string b){
    int counter=0;
    x=(int)a[counter];
    y=(int)b[counter];
    if (x<y){
        return true;
    } else{

        while(x==y and counter-1<(int)a.length()){
            
            counter++;
            x=(int)a[counter];
            y=(int)b[counter];
            if (x!=y){
                break;
            }        
        }
        return x<y;
    }


}

int main(){
    int n, l;  cin>>n>>l;
    vector<string> strings;
    while(n--){
        string s; cin>>s; strings.push_back(s);
    }
    sort(strings.begin(),strings.end(),cmp);
    string res="";
    for (int i=0;i<strings.size();i++){
        res+=strings[i];
    }
    cout<<res<<'\n';

}
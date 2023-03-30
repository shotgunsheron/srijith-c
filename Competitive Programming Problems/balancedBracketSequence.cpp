#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> layers(2*n);
        int cur=0;
        for (int i=1;i<s.length();i++){
            if (s[i]==')' and s[i-1]=='('){
                layers[i]=cur;
            } else if (s[i]==')' and s[i-1]==')'){
                cur--;
                layers[i]=cur;
            } else if (s[i]=='(' and s[i-1]=='('){
                cur++;
                layers[i]=cur;
            } else{
                layers[i]=cur;
            }
        }
        stack<int> stack;
        vector<int> p(2*n);
        for (int i=0;i<s.length();i++){
            if (s[i]=='('){
                stack.push(i);
            } else{
                p[stack.top()]=i;
                stack.pop();
            }
        }

        int ans=0;
        vector<bool> visited(2*n,false);
        for (int i=0;i<layers.size();i++){
            if (!visited[i]){
                int counter=p[i];
                int curLayer=layers[i];
                

                if (counter!=i+1){
                    ans++;
                }
                visited[counter]=true;
            }
        }
        cout<<ans+1<<'\n';
    }
}
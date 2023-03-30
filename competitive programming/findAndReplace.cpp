#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){        
        string s; cin>>s;
        string s2; cin>>s2;
        unordered_set<char> st;
        for (int i=0;i<s.length();i++){
            st.insert(s[i]);
        }
        int numDistinct=st.size();
        vector<vector<int>> indices(52);

        for (int i=0;i<s.length();i++){
            indices[s[i]-(((!isupper(s[i]))?'a':('A'-26)))].push_back(i);
        }
        int ans=0;
        bool res=true;
        for (int i=0;i<indices.size();i++){
            if (indices[i].size()!=0){
                int curVal=s2[indices[i][0]];
                for (int j=1;j<indices[i].size();j++){
                    if (s2[indices[i][j]]!=curVal){
                        res=false;
                        break;
                    }
                }
            }

        }
        long long distinct=st.size();
        set<char> used;
        for (long long i=0;i<s.length();i++){
            char x=s[i];
            char y=s2[i];
            if (x!=y and used.count(x)==0){
                //make all chars at indices of x = to y
                //if there is already a character with value y in s and it doesn't remain the same, 
                //then use two operations if there are enough distinct characters available
                //if there is already a char with value y in s but it remains the same, make chars at indices of x=to y
                used.insert(x);
                if (st.count(y)>0){
                    if (s2[indices[y-(((!isupper(y))?'a':('A'-26)))][0]]!=y){
                        ans+=2;
                    } else{
                        ans++;
                    }
                } else{
                    ans++;
                }

            }
            st.erase(x);

        }

        if (res==false){
            cout<<-1<<'\n';
        } else{
            cout<<ans<<'\n';

        }

    }

}
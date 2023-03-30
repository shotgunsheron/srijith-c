#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> arr(n+1,"");
    vector<vector<int>> arr2;

    vector<int> prices;
    for (int i=0;i<n;i++){
        string s; cin>>s;
        int x; cin>>x;
        prices.push_back(x);
        arr[i]=(s+'X');
        vector<int> v(n,0);
        v.push_back(x);
        arr2.push_back(v);
    }
    vector<int> v;
    for (int i=0;i<n;i++){
        arr[n]+='X';
        int x; cin>>x;
        v.push_back(x);
    }
    arr2.push_back(v);
    int q; cin>>q;
    for (int i=0;i<q+1;i++){
        if (i!=0){
            int a, b; cin>>a>>b;
            if (arr[a-1][b-1]=='R'){
                arr[a-1][b-1]='D';
            } else{
                arr[a-1][b-1]='R';
            }
        }
        set<vector<int>> visited;
        int currAns=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int x=i;
                int y=j;
                int currCount=0;
                while(arr[x][y]!='X'){
                    if (visited.count({x,y})>0){
                        break;
                    }
                    visited.insert({x,y});

                    currCount++;
                    if (arr[x][y]=='R'){
                        y++;
                    } else if (arr[x][y]=='D'){
                        x++;
                    }
                }
                currAns+=arr2[x][y]*currCount;

            }
        }    
        cout<<currAns<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> l;
    vector<int> r;
    vector<vector<int>> segments;
    while(n--){
        int x;
        cin>>x;
        l.push_back(x);
        int y;
        cin>>y;
        r.push_back(y);
        vector<int> tempVec={x,y};
        segments.push_back(tempVec);
    }
    int lBorder=*min_element(l.begin(),l.end());
    int rBorder=*max_element(r.begin(),r.end());
    int res=0;
    for (int i=0;i<segments.size();i++){
        if (segments[i][0]==lBorder and segments[i][1]==rBorder){
            res=i+1;
            break;
        }
    }
    if (res==0){
        cout<<-1<<'\n';
    } else{
        cout<<res<<'\n';

    }

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> plane;
    while(n--){
        int x;
        cin>>x;
        int y;
        cin>>y;
        vector<int>coordinates={x,y};
        plane.push_back(coordinates);
    }

    int res=0;
    for (int i=0;i<plane.size();i++){
        bool a=false;
        bool b=false;
        bool c=false;
        bool d=false;
        for (int k=0;k<plane.size();k++){
            if (plane[k][0]>plane[i][0] and plane[k][1]==plane[i][1]){
                a=true;
            } else if (plane[k][0]<plane[i][0] and plane[k][1]==plane[i][1]){
                b=true;
            } else if (plane[k][0]==plane[i][0] and plane[k][1]>plane[i][1]){
                c=true;
            } else if (plane[k][0]==plane[i][0] and plane[k][1]<plane[i][1]){
                d=true;
            }
            if (a==true and b==true and c==true and d==true){
                res++;
                break;
            }
        }
    }
    cout<<res<<'\n';
}
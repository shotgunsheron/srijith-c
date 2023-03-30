#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr={{0,0,0},{0,0,0},{0,0,0}};

    for (int v=0;v<3;v++){
        for (int e=0;e<3;e++){
            int x;
            cin>>x;
            arr[v][e]=x;
        }
    }
    vector<vector<int>> toggles={{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int>> res={{0,0,0},{0,0,0},{0,0,0}};
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            //if corner piece
            int val=arr[i][j];
            toggles[i][j]+=val;

            if (i==0 and j==0 or i==0 and j==2 or i==2 and j==0 or i==2 and j==2){

                if (i==0 and j==0){
                    toggles[0][1]+=val;
                    toggles[1][0]+=val;
                }
                else if (i==0 and j==2){
                    toggles[0][1]+=val;
                    toggles[1][2]+=val;
                } else if (i==2 and j==0){
                    toggles[1][0]+=val;
                    toggles[2][1]+=val;
                } else if (i==2 and j==2){
                    toggles[1][2]+=val;
                    toggles[2][1]+=val;
                }
            }
            else if (i==1 and j==0 or i==2 and j==1 or i==1 and j==2 or i==0 and j==1){
                if (i==1 and j==0){
                    toggles[0][0]+=val;
                    toggles[2][0]+=val;
                    toggles[1][1]+=val;
                } else if (i==1 and j==2){
                    toggles[0][2]+=val;
                    toggles[2][2]+=val;
                    toggles[1][1]+=val;
                } else if (i==0 and j==1){
                    toggles[0][0]+=val;
                    toggles[0][2]+=val;
                    toggles[1][1]+=val;
                } else if (i==2 and j==1){
                    toggles[2][0]+=val;
                    toggles[2][2]+=val;
                    toggles[1][1]+=val;
                }
            }
            else if (i==1 and j==1){
                toggles[0][1]+=val;
                toggles[1][0]+=val;
                toggles[2][1]+=val;
                toggles[1][2]+=val;
            }
       }
    }

    for (int x = 0; x < toggles.size(); x++)
{
    for (int y = 0; y < toggles[0].size(); y++)
    {
        if (toggles[x][y]%2==0){
            res[x][y]=1;
        } else{
            res[x][y]=0;
        }
    }
}
        for (int f = 0; f < res.size(); f++)
{
    for (int g = 0; g < res[0].size(); g++)
    {
        cout<<res[f][g];
    }
    cout<<'\n';
}
}
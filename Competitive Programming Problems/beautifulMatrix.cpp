#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    vector<vector<int>> matrix;
    int xCoordinate;
    int yCoordinate;
    while(n--){
        vector<int> tempRow;
        for (int i=0;i<5;i++){
            int x;
            cin>>x;
            if (x==1){
                xCoordinate=i;
                yCoordinate=n;
            }
            tempRow.push_back(x);
        }
        matrix.push_back(tempRow);
    }
    //for (int i=0;i<5;i++){
    //    for (int j=0;j<5;j++){
    //        cout<<matrix[i][j]<<" ";
    //    }
    //    cout<<'\n';
    //}
    //cout<<xCoordinate<<" "<<yCoordinate<<'\n';
    int res=0;
    res+=abs(2-xCoordinate);
    res+=abs(2-yCoordinate);
    cout<<res<<'\n';
}
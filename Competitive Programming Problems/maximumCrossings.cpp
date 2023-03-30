#include <bits/stdc++.h>
using namespace std;

bool isPartiallyIntersecting(vector<int> x, vector<int>y){
    bool res=true;
    if (y[0]>x[0] and y[1]>x[1] or y[0]<x[0] and y[1]<x[1]){
        res=false;
    }
    if (y[0]==x[0] or y[1]==x[1]){
        res=true;
    }
    return res;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int nT=n;
        vector<int> arr;
        while(nT--){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        vector<vector<int>> wires;
        for (int h=1;h<=n;h++){
            vector<int>tempArr;
            tempArr.push_back(h);
            tempArr.push_back(arr[h-1]);
            wires.push_back(tempArr);
        }
        int jC=0;
        int res=0;
        for (int i=0;i<wires.size();i++){
            for (int j=jC;j<wires.size();j++){
                if (wires[i]!=wires[j] and i<j and isPartiallyIntersecting(wires[i],wires[j])){
                    res++;
                    //cout<<"I J is: "<<i<<' '<<j<<'\n';
                }
            }
            jC++;

        }

        //for (int k=0;k<wires.size();k++){
        //    cout<<wires[k][0]<<" "<<wires[k][1]<<'\n';
        //}
        cout <<res<<'\n';
    }
}
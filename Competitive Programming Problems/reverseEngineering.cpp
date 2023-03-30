#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<string> arr;
        vector<int>  outputs;
        while(m--){
            string x;
            cin>>x;
            arr.push_back(x);
            int y; cin>>y;
            outputs.push_back(y);
        }
        bool res=false;
        int count=0;
        for (int i=0;i<n;i++){
            for (int v=0;v<=1;v++){
                for (int o=0;o<=1;o++){
                    bool currRes=true;
                    bool isOne=false;
                    bool isZero=false;
                    for (int j=0;j<arr.size();j++){
                        if (arr[j][i]==char(v+'0') and outputs[j]!=o){
                            currRes=false;
                        }
                        if (arr[j][i]=='1'){
                            isOne=true;
                        }
                        if (arr[j][i]=='0'){
                            isZero=true;
                        }
                    }
                    if (currRes==true){
                        if (isZero and v==0 or isOne and v==1){
                            res=true;

                        }
                    }
                }
            }
        }
        if (res){
            cout<<"OK"<<'\n';
        } else{
            cout<<"LIE"<<'\n';
        }
    }
    
}
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long t; cin>>t;
    while(t--){
        long long n, m; cin>>n>>m;
        vector<string> arr;
        vector<long long>  outputs;
        while(m--){
            string x;
            cin>>x;
            arr.push_back(x);
            long long y; cin>>y;
            outputs.push_back(y);
        }
        bool res=false;
        long long count=0;
        for (long long i=0;i<n;i++){
            for (long long v=0;v<=1;v++){
                for (long long o=0;o<=1;o++){
                    bool currRes=true;
                    bool isOne=false;
                    bool isZero=false;
                    vector<long long> pos;
                    for (long long j=0;j<arr.size();j++){
                        if (arr[j][i]==char(v+'0') and outputs[j]!=o){
                            currRes=false;
                        }
                        if (arr[j][i]==char(v+'0') and outputs[j]==o){
                            pos.push_back((j));
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
                            //res=true;
                            for (long long k=0;k<pos.size();k++){
                                arr[pos[k]]="";
                                for (long long g=0;g<n;g++){
                                    arr[pos[k]]+='X';
                                }
                            }
                        }
                    }
                }
            }
        }
        string e="";
        for (long long i=0;i<n;i++){
            e+='X';
        }
        bool ans=true;
        for (long long i=0;i<arr.size();i++){
            if (arr[i]!=e){
                ans=false;
                break;
            }
        }
        if (ans){
            cout<<"OK"<<'\n';
        }  else{
            cout<<"LIE"<<'\n';
        }
    }
    
}
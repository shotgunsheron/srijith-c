#include <bits/stdc++.h>
#include <iterator>
#include <map>
using namespace std;

int main(){
    long long n;
    cin>>n;
    map<long long, char> cows;
    vector<long long> cowIndexes;


    long long size=n;
    while(n--){
        long long x;
        cin>>x;
        char t;
        cin>>t;
        cows.insert(pair<long long,char>(x,t));
        cowIndexes.push_back(x);
    }
    long long r=size;
    long long maxSize=0;
    sort(cowIndexes.begin(),cowIndexes.end());
    while (size--){
        for (long long k=0;k<=r-size;k++){
            long long currH=0;
            long long currG=0;
            long long starter=k;
            long long starterVal=0;
            long long endVal=0;
            //cout<<'\n';
            for (long long i=starter;i<=size;i++){
                //cout<<cowIndexes[i]<<'\n';
                if (i==starter){
                    starterVal=cowIndexes[i];
                } else if (i==size){
                    endVal=cowIndexes[i];
                }
                if (cows[cowIndexes[i]]=='H'){
                    currH++;
                } else{
                    currG++;
                }
            } 
            if (currH==currG){
                if (endVal-starterVal>maxSize){
                    maxSize=endVal-starterVal;
                    //cout<<"YES"<<'\n';

                }
            }
        }
    }
    cout<<maxSize<<'\n';

}
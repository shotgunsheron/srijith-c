#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long n2=n;
    long long arr[100000];
    vector<long long> sequences;
    while(n--){
        long long x; cin>>x; sequences.push_back(x);
    }
    vector<vector<long long>> subSequences;
    vector<long long> falseInts;
    for (long long i=0;i<n2;i++){
        long long distance=0;
        bool r=true;
        bool firstTime=false;
        bool onlyElement=false;
        long long offSet=0;
        //cout<<i<<'\n';
        //for (long long v=0;v<sequences.size();v++){
        //    cout<<sequences[v]<<' ';
        //}
        //cout<<'\n';
        for (long long k=i+1;k<n2;k++){
            if (sequences[k]==-1){
                //cout<<"Hit -1 at: "<<i<<' '<<k<<'\n';
            } else{
                if (sequences[i]==sequences[k] and firstTime==false){
                    firstTime=true;
                    distance=k-i;
                    offSet+=distance;
                    sequences[k]=-1;
                    onlyElement=false;
                    //cout<<"First time at: "<<i<<' '<<k<<'\n';
                } else if (sequences[i]==sequences[k] and firstTime==true){
                    if (k-i-offSet==distance){
                        //cout<<"True at: "<<i<<' '<<k<<' '<<distance<<' '<<offSet<<'\n';

                        offSet+=distance;
                    } else if (k-i-offSet!=distance){
                        //cout<<"False at: "<<i<<' '<<k<<' '<<distance<<' '<<offSet<<'\n';
                        r=false;
                    }
                    sequences[k]=-1;
                }
            }
        }
        if (r==true and sequences[i]!=-1 and onlyElement==false){
            vector<long long> tempVec={sequences[i],distance};
            subSequences.push_back(tempVec);
        } else if (onlyElement==true and sequences[i]!=-1 and r==true){
            vector<long long> tempVec={sequences[i],0};
            subSequences.push_back(tempVec);
        }
    }

    cout<<subSequences.size()<<'\n';
    vector<long long> sortSequences;
    for (long long g=0;g<subSequences.size();g++){
        sortSequences.push_back(subSequences[g][0]);
    }
    sort(sortSequences.begin(),sortSequences.end());

    for (long long a=0;a<subSequences.size();a++){
        for (long long h=0;h<sortSequences.size();h++){
            if (sortSequences[a]==subSequences[h][0]){
                cout<<subSequences[h][0]<<' '<<subSequences[h][1]<<'\n';
            }
        }
    }

}
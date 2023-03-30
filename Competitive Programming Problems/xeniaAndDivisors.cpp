#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int ones=0;
    int twos=0;
    int threes=0;
    int fours=0;
    int sixes=0;

    bool exit=false;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
        if (x==5 or x==7){
            exit=true;
            break;
        }
        if(x==1){
            ones++;
        }
        if (x==2){
            twos++;
        }
        if (x==3){
            threes++;
        } 
        if (x==4){
            fours++;
        }
        if (x==6){
            sixes++;
        }

        
    }
    vector<vector<int>> results;
    if (exit){
        cout<<-1<<'\n';
    } else{
        if (ones==arr.size()/3){
            int partitions=arr.size()/3;
            for (int i=0;i<threes;i++){
                if (sixes>0){
                    sixes--;
                    vector<int> tempVec={1,3,6};
                    results.push_back(tempVec);
                } else{
                    exit=true;
                }
            }
            if (twos==fours+sixes and exit==false){
                for (int i=0;i<twos;i++){
                    if (fours>0){
                        vector<int> tempVec={1,2,4};
                        results.push_back(tempVec);
                        fours--;
                    } else if (sixes>0){
                        vector<int> tempVec={1,2,6};
                        results.push_back(tempVec);
                        sixes--;
                    }
                }
            }
        }
        if (fours>0 or sixes>0){
            cout<<-1<<'\n';
        } else if (results.size()<arr.size()/3){
            cout<<-1<<'\n';
        } else{
            for (int i=0;i<results.size();i++){
                for (int j=0;j<3;j++){
                    cout<<results[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
//find biggest element closest to the left side.
//find smallest element closest to the right side.
//find distance between indices of previous values to their respective sides. add this to res.
//if biggest and smallest are in the way of each other, subtract res by 1

int main(){
    vector<int> soldiers;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        soldiers.push_back(x);
    }
    int res=0;
    int bigIndex=0;
    int bigVal=*max_element(soldiers.begin(), soldiers.end());
    int smallIndex=soldiers.size()-1;
    int smallVal=*min_element(soldiers.begin(), soldiers.end());
    while (soldiers[bigIndex]!=bigVal){
        bigIndex++;
    }
    while (soldiers[smallIndex]!=smallVal){
        smallIndex--;
    }
    res+=bigIndex;
    res+=soldiers.size()-1-smallIndex;
    if (bigIndex>smallIndex){
        res--;
    }
    cout<<res<<'\n';
}
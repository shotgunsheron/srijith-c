#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin>>k;
    vector<int> months;
    for (int i=0;i<12;i++){
        int x;
        cin>>x;
        months.push_back(x);
    }
    int height=0;
    int res=0;
    sort(months.begin(),months.end(),greater<int>());
    while(height<k){
        height+=months[res];
        if (res==months.size()-1 and height<k){
            res=-1;
            break;
        } else{
            res++;
        

        }
    }
    cout<<res<<'\n';
}
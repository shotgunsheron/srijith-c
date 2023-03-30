#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    int c;
    int d;
    cin>>c;
    cin>>d;
    int sum=0;
    if (b<d and b>c and a<c){
        sum=d-a;
    } else if (d>a and d<b and c<a){
        sum=b-c;
    } else if (b<d and a>c){
        sum=d-c;
    } else if (d<b and c>a){
        sum=b-a;
    } else if (a==b or a==c or a==d or b==c or b==d or c==d){
        vector<int> vars={a,b,c,d};
        sort(vars.begin(), vars.end());
        sum=vars[3]-vars[0];
    }
    cout<<sum<<'\n';
}
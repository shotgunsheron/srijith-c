#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np=0;
    cin>>n;
    cin>>k;
    cin>>l;
    cin>>c;
    cin>>d;
    cin>>p;
    cin>>nl;
    cin>>np;
    k=floor((k*l)/(nl*n));
    c=floor((c*d)/n);
    p=floor(p/(np*n));
    vector<int> nums = {k,c,p};
    sort(nums.begin(),nums.end());
    cout<<nums[0]<<'\n';

}
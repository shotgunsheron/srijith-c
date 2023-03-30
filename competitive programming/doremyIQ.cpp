#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    for(int h=1;h<=t;h++){
    long long n,q; cin>>n>>q;
    map<long long,long long> count;
    vector<long long> a;
    multiset<int> st;
    for (long long i=0;i<n;i++){
        long long x; cin>>x;
        a.push_back(x);
        st.insert(x);
        count[x]++;
    }
    
    string ans="";
    for (long long i=0;i<n;i++){
        int x=
        if (q>=n-){
            ans+='1';
        }//
        else if (q>0){
            if (a[i]>q){
                if (count[q]==0){
                    ans+='1';
                    q--;
                } else{

                        ans+='0';

                    
                }
            } else{
                ans+='1';
            }
        } else{
            ans+='0';
        }
        count[a[i]]--;
        //erase element from st
        st.erase(st.lower_bound(a[i]));

    }
    
    cout<<ans<<'\n';
    }
}
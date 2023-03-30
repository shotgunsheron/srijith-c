#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n,m,k; cin>>n>>m>>k;
        vector<long long> colors(k);

        for (long long i=0;i<k;i++){
            cin>>colors[i];
        }
        bool ans=false;
        bool finalAns=false;
        //first test with column stripes
        long long totalStripes=0;
        vector<long long> stripes;
        for (long long i=0;i<k;i++){
            if (colors[i]/n>=2){
                totalStripes+=colors[i]/n;
                stripes.push_back(colors[i]/n);
            }
        }
        sort(stripes.begin(),stripes.end(),greater<long long>());
        if (m%2==0){
            if (totalStripes>=m and (n>=2 and m>2 or n>2 and m>=2)){
                ans=true;
            }
        } else{
            long long tmpStripes=totalStripes;
            //cout<<tmpStripes<<'\n';
            long long i=0;
            bool flag=false;

            if (tmpStripes==m) {
                flag=true;
            }


            while(i<stripes.size()){
                if ((tmpStripes-=(stripes[i]-2))<=m){
                    flag=true;
                    break;
                }
                i++;
            }

            if (flag and totalStripes>=m and (n>=2 and m>2 or n>2 and m>=2)){
                ans=true;
            } 
        }
        //next test with row stripes
        long long totalStripes2=0;
        vector<long long> stripes2;
        for (long long i=0;i<k;i++){
            if (colors[i]/m>=2){
                totalStripes2+=colors[i]/m;
                stripes2.push_back(colors[i]/m);
            }
        }
        sort(stripes2.begin(),stripes2.end(),greater<long long>());
        if (n%2==0){
            if (totalStripes2>=n and (n>=2 and m>2 or n>2 and m>=2)){
                ans=true;
            }
        } else{
            long long tmpStripes=totalStripes2;
            long long i=0;
            bool flag=false;
            if (tmpStripes==n) {
                flag=true;
            }
            while(i<stripes2.size()){
                if ((tmpStripes-=(stripes2[i]-2))<=n){
                    flag=true;
                    break;
                }
                i++;
            }
            if (flag==true and totalStripes2>=n and (n>=2 and m>2 or n>2 and m>=2)){
                ans=true;
            }
        }

        if (ans){
            cout<<"YES"<<'\n';
        } else{
            cout<<"NO"<<'\n';
        }
    }

}
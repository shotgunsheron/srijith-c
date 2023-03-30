#include <bits/stdc++.h>
using namespace std;


bool cmp(vector<long long> a,vector<long long> b){
    return (a[2]<b[2]);
}


int main(){
    long long g,n; cin>>g>>n;
    vector<vector<long long>> grazes;
    vector<long long> times;
    for (long long i=0;i<g;i++){
        long long x,y,t; cin>>x>>y>>t;
        grazes.push_back({x,y,t});
    }
    long long ans=0;

    sort(grazes.begin(),grazes.end(),cmp);
    for (long long i=0;i<grazes.size();i++){
        times.push_back(grazes[i][2]);
    }
    for (long long i=0;i<n;i++){

        long long x,y,t; cin>>x>>y>>t;

        //long long index = binarySearch(grazes,0,g-1,t);
        //long long index=binarySearch(grazes,0,g-1,t);
        
        long long index=lower_bound(times.begin(),times.end(),t)-times.begin();
        index--;
        long long res=0;
        if (index==-1){
            //nothing was less than or equal to alibi;
            long long distance=(long long)(ceil(sqrt((long long)((x-grazes[0][0])*(x-grazes[0][0])+(y-grazes[0][1])*(y-grazes[0][1])))));

            if (t+distance>grazes[0][2]){
                res=1;
            }
        } else if (index==g-1){
            //nothing was greater than alibi
            long long distance=(long long)(ceil(sqrt((long long)((x-grazes[g-1][0])*(x-grazes[g-1][0])+(y-grazes[g-1][1])*(y-grazes[g-1][1])))));

            if (grazes[g-1][2]+distance>t){
                res=1;
            }
            
        } else{
            //middle
            long long distance=(long long)(ceil(sqrt((long long)((x-grazes[index][0])*(x-grazes[index][0])+(y-grazes[index][1])*(y-grazes[index][1])))));
            if (grazes[index][2]+distance>t){
                res=1;
            } else{
                distance=(long long)(ceil(sqrt((long long)((x-grazes[index+1][0])*(x-grazes[index+1][0])+(y-grazes[index+1][1])*(y-grazes[index+1][1])))));
                if (t+distance>grazes[index+1][2]){
                    res=1;
                }
            }
        }

        index++;

        //either before the grazes, middle of the grazes, or after the grazes
        ans+=res;

    }
    cout<<ans<<'\n';
}
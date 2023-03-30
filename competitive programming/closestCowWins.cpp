#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k, m, n; cin>>k>>m>>n;
    vector<pair<long long,long long>> patches(k+m);
    for (long long i=0;i<k;i++){
        cin>>patches[i].first>>patches[i].second;
    }
    for (long long i=k;i<k+m;i++){
        cin>>patches[i].first; patches[i].second=-1;
    }
	sort(begin(patches), end(patches));

    long long last_i=-1;
    vector<long long> res;
    for (long long i=0;i<patches.size();i++){

        if (patches[i].second==-1){

            if (last_i==-1){
                last_i=i;
            } else{
                //start the search
                //first loop through all starting cow values

                long long cur_sum=0;
                long long max_sum=0;
                long long total_sum=0;
                long long r=last_i+1;
                for (long long j=last_i+1;j<i;j++){
                    total_sum+=patches[j].second;
                    cur_sum=0;

                    while(patches[r].first-patches[j].first<patches[i].first-patches[last_i].first and r<i){
                        cur_sum+=patches[r].second;
                        r++;
                    }
                    max_sum=max(max_sum, cur_sum);
                    res.push_back(max_sum); res.push_back(total_sum-max_sum);
                    cur_sum-=patches[j].second;
                }

            }
            last_i=i;

        }
    }
    long long lSum=0;
    for (long long i=0;patches[i].second!=-1 and i<patches.size();i++){
        lSum+=patches[i].second;
    }
    res.push_back(lSum);
    long long rSum=0;
    for (long long i=last_i+1;i<patches.size();i++){
        rSum+=patches[i].second;
    }
    res.push_back(lSum);
    sort(res.begin(),res.end(), greater<long long>());
    long long ans=0;
    for (long long i=0;i<n;i++){
        ans+=res[i];
    }
    cout<<ans<<'\n';
}
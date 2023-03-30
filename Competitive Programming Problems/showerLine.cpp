#include <bits/stdc++.h>
using namespace std;

int main(){
    //vector<int> v={1,2,3,4,5};
    string v="12345";
    vector<vector<int>> g;
    for (int i=0;i<5;i++){
        vector<int> tempVec;
        for (int j=0;j<5;j++){
            int x;
            cin>>x;
            tempVec.push_back(x);
        }

        g.push_back(tempVec);
    }
    std::sort(v.begin(), v.end());
    vector<int> results;
    do {
        int res=0;
        vector<int> intArr;
        for (int i=0;i<v.size();i++){
            intArr.push_back(v[i]-'0'-1);
        }
        res+=g[intArr[0] ][intArr[1] ];
        res+=g[intArr[1] ][intArr[0] ];
        res+=g[intArr[2] ][intArr[3] ];
        res+=g[intArr[3] ][intArr[2] ];

        res+=g[intArr[1] ][intArr[2] ];
        res+=g[intArr[2] ][intArr[1] ];
        res+=g[intArr[3] ][intArr[4] ];
        res+=g[intArr[4] ][intArr[3] ];

        res+=g[intArr[2] ][intArr[3] ];
        res+=g[intArr[3] ][intArr[2] ];

        res+=g[intArr[3] ][intArr[4] ];
        res+=g[intArr[4] ][intArr[3] ];

        results.push_back(res);
    } while(std::next_permutation(v.begin(), v.end()));
    
    cout<<*max_element(results.begin(),results.end())<<'\n';
}
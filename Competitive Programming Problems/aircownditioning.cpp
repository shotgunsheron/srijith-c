
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "9") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		//freopen((name + ".out").c_str(), "w", stdout);
	}
}


vector<int> command(vector<int> a, int startIndex, int endIndex){
    int num=0;
    if (a[startIndex]>0){
        int minNum=10001;
        for (int i=startIndex; i<endIndex; i++){
            minNum=min(minNum,a[i]);
        }
        for (int i=startIndex; i<endIndex;i++){
            a[i]-=minNum;
        }        
        num=minNum;
    } else{
        int minNum=-10000000;
        for (int i=startIndex; i<endIndex; i++){

            minNum=max(minNum,a[i]);
        }
        for (int i=startIndex; i<endIndex;i++){
            a[i]-=minNum;
        }                
        num=minNum;
    }
    a.push_back(num);
    return a;
}

int main(){
    setIO();
    int n; cin>>n;
    vector<int> a,arr;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for (int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(a[i]-x);
    }

    int startIndex=0;
    int endIndex=0;
    int sum=1;
    int ans=0;
    while(sum!=0){
        sum=0;
        for (int i=0;i<arr.size();i++){
            if (arr[i]!=0){
                if (arr[i-1]==0){
                startIndex=i;
                endIndex=i+1;
                int counter=i+1;
                bool sign;
                if (arr[i]>0){
                    sign=true;
                } else{
                    sign=false;
                }
                while(counter<arr.size() and arr[counter]!=0 and arr[counter]>0 and sign==true or counter<arr.size() and arr[counter]!=0 and arr[counter]<0 and sign==false){
                    counter++;
                    endIndex=counter;
                }
                arr=command(arr,startIndex,endIndex);
                ans+=abs(arr[arr.size()-1]);
                arr.pop_back();
                }
            }
            sum+=arr[i];
            
        }

    }

    cout<<ans<<'\n';
}
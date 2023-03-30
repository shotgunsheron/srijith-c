#include <bits/stdc++.h>
using namespace std;


int numberOfPaths(int m, int n)
{
    //m is down
    //n is right
    // We have to calculate m+n-2 C n-1 here
    // which will be (m+n-2)! / (n-1)! (m-1)!
    int path = 1;
    for (int i = n; i < (m + n - 1); i++) {
        path *= i;
        path /= (i - n + 1);
    }
    return path;
}

int main(){
    int h, w, a, b; cin>>h>>w>>a>>b;
    int ans=0;
    for (int i=1;i<=h-a;i++){
        int d=i-1;
        int r=b-1;
        int paths1=numberOfPaths(d,r);
        int d2=h-i;
        int r2=w-b;
        int paths2=numberOfPaths(d2,r2);
        ans+=(paths1)*(paths2);

    }
    cout<<ans<<'\n';
}
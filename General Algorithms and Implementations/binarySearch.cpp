#include <bits/stdc++.h>
using namespace std;


long long binarySearch(vector<vector<long long>> arr, long long l, long long r, long long x)
{
    long long mid = l + (r - l) / 2;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid][2] == x)
            return mid;
        if (arr[mid][2] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return mid;
}

int main(){
    vector<vector<long long>> arr={{0,0,2},{0,0,3},{0,0,4},{0,0,5}};
    int x; cin>>x;

    int index=binarySearch(arr,0,arr.size()-1,x);
    index--;
    cout<<index<<'\n';
}

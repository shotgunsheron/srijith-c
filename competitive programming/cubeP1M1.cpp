#include <bits/stdc++.h>
using namespace std;


vector<int> reduceFraction(int x, int y)
{
    int d;
    d = __gcd(x, y);
 
    x = x / d;
    y = y / d;
    
    return {x,y};
    
}
int main(){
    long long numerator=1;
    long long denominator=1;
    vector<int> arr;
    for (int i=2;i<=16;i++){
        numerator*=(i*i*i-1);
        denominator*=(i*i*i+1);
        arr=reduceFraction(numerator,denominator);
        numerator=arr[0];
        denominator=arr[1];
    }
    cout<<numerator<<' ' <<denominator<<'\n';
}
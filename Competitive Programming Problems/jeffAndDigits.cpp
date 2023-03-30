#include <bits/stdc++.h>
using namespace std;
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
int main(){
    long long n;
    cin>>n;
    long long sumOfDigits=0;
    bool hasZero=false;
    long long z=0;
    long long f=0;
    while(n--){
        long long x;
        cin>>x;
        sumOfDigits+=x;
        if (x==0){
            z++;
        } else{
            f++;
        }

    }
    string res="";
    if (z==0){
        cout<<"-1\n";
    } else{
        sumOfDigits=sumOfDigits/45*45;
        for (int i=0;i<sumOfDigits/5;i++){
            res+='5';
        }
        while(z--){
            res+='0';
        }
        if (sumOfDigits<45){
            res="0";
        }

        cout<<res<<'\n';

    }




}
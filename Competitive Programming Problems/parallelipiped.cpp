#include <bits/stdc++.h>
using namespace std;

int main(){
    int s1;
    int s2;
    int s3;
    cin>>s1>>s2>>s3;
    int b=sqrt(s1*s2/s3);
    int a=s1/b;
    int c=s2/b;
    cout<<4*(a+b+c)<<'\n';
}
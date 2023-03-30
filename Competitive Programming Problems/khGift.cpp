#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a=0;
    int b=0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (x==100){
            a++;
        } else{
            b++;
        }
    }

    if (a==b and a%2==0){
        cout<<"YES"<<'\n';
    } else{
        bool breakVal=false;
        int x=0;
        int y=0;
        for (int i=0;i<=a;i++){
            for (int j=0;j<=b;j++){
                if (100*i+200*j==100*(a-i)+200*(b-j)){
                    cout<<"YES"<<'\n';
                    breakVal=true;
                    break;
                }
            }
            if (breakVal){
                break;
            }
        }
        if (breakVal==false){
            cout<<"NO"<<'\n';
        }
    }

}
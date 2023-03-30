#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool res=true;
    int x=0;
    int y=0;
    int z=0;
    while(n--){
        for(int i=0;i<3;i++){
            int g;
            cin>>g;
            if (i==0){
                x+=g;
            }
            else if(i==1){
                y+=g;
            } else{
                z+=g;
            }
        }

    }
        if (x==0 and y==0 and z==0){
            cout<<"YES"<<'\n';
        } else{
            cout<<"NO"<<'\n';
        }

}
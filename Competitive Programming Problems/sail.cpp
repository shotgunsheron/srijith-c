#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, sx, sy, ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    int xDistance=ex-sx;
    int yDistance=ey-sy;
    int res=0;
    int r=t;
    while(t--){
        char x;
        cin>>x;
        if (xDistance>0){
            if (x=='E'){
                xDistance--;
            }
        } else if (xDistance<0){
            if (x=='W'){
                xDistance++;
            }
        } 
        if (yDistance>0){
            if (x=='N'){
                yDistance--;
            }
        } else if (yDistance<0){
            if (x=='S'){
                yDistance++;
            }
        }
        if (xDistance==0 and yDistance==0){
            cout<<r-t<<'\n';
            break;
        }
        else if (t==0){
            cout<<-1<<'\n';
            break;
        }
    }

}
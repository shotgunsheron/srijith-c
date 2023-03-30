#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main(){
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    vector<int> a;
    for  (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    bool turn=true;
    for (int i=0;i<n;i++, i=i%n){
        if (a[i]==0){
            break;
        } 
        for (int j=a[i];j>=1;j--){
            if (j==1){
                a[i]--;
                break;
            }
            if (isPrime(j)){

                if (!isPrime(a[i]-j)){
                    a[i]-=j;
                    break;
                }
            } 
        }

        turn=!turn;
        if (a[i]==0){
            break;
        } 
        for (int j=a[i];j>=1;j--){
            if (j==1){
                a[i]--;
                break;
            }
            if (isPrime(j)){

                if (!isPrime(a[i]-j)){
                    a[i]-=j;
                    break;
                }
            } 
        }

        turn=!turn;
    }
    turn=!turn;
    if (turn==true){
        cout<<"Farmer John"<<'\n';
    } else{
        cout<<"Farmer Nhoj"<<'\n';
    }
}
}
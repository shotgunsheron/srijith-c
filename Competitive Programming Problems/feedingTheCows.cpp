#include  <bits/stdc++.h>
using namespace std;



int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        string master=s;
        string t=s;

        bool quit=false;
        int pastHay=-1;

        while(quit==false){
            int lPoint=-1;
            int hayPoint=-1;
            quit=true;
            for  (int i=pastHay+1;i<s.length();i++){
                if (s[i]=='G'){
                    lPoint=i;
                    hayPoint=min(lPoint+k,int(s.length()-1));
                    quit=false;
                    break;
                } 
            }
            if (quit==false){
                int rPoint=min(hayPoint+k,int(s.length()-1));
                while(s[rPoint]!='G' and rPoint>hayPoint){
                    rPoint--;
                }
                for (int i=lPoint;i<=rPoint;i++){
                    s[i]='.';
                }
                s[hayPoint]='G';
                pastHay=hayPoint;
            }
        }
        quit=false;
        pastHay=-1;

        while(quit==false){
            int lPoint=-1;
            int hayPoint=-1;
            quit=true;
            for  (int i=pastHay+1;i<t.length();i++){
                if (t[i]=='H'){
                    lPoint=i;
                    hayPoint=min(lPoint+k,int(t.length()-1));
                    while(s[hayPoint]=='G'){
                        hayPoint--;
                    }
                    quit=false;
                    break;
                } 
            }
            if (quit==false){
                int rPoint=min(hayPoint+k,int(t.length()-1));
                while(t[rPoint]!='H' and rPoint>hayPoint){
                    rPoint--;
                }
                for (int i=lPoint;i<=rPoint;i++){
                    t[i]='.';
                }
                t[hayPoint]='H';
                pastHay=hayPoint;
            }
        }

        string res="";
        int num=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='G'){
                res+='G';
                num++;
            } else if (t[i]=='H'){
                res+='H';
                num++;
            } else{
                res+='.';
            }
        }
        cout<<num<<'\n';
        cout<<res<<'\n';
    }
}
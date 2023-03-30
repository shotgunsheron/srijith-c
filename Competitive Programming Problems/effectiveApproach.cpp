#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long pos[n];
	for (long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		pos[x]=i;
	}
	long long p;
	cin>>p;
	long long resX=0;
	long long resY=0;
	for (long long k=1;k<=p;k++){
		long long x;
		cin>>x;
		resX+=pos[x];
		resY+=n-pos[x]+1;
	}
	cout<<resX<<" "<<resY<<'\n';
	
	
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,b,i,j;	cin>>T;
	while(T--)
	{
		long long int n,b;	cin>>n>>b;
		j=floor(n/2.0);
		if(j%b)				j=j+(b-j%b);
		long long int t=(n-j)*(j/b);
		j=ceil(n/2.0);
		if(j%b)				j=j-j%b;
		long long int f=(n-j)*(j/b);
		long long int ans=max(f,t);
		printf("%lld\n",ans);
	}
}

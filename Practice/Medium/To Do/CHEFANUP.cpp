#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,k,l,i,m=1;	cin>>n>>k>>l;
		for(i=0;i<n;i++)	
			m=m*k;
		for(i=0;i<n;i++)
		{
			long long int q=l/m;
			cout<<(q+1)<<" ";
			l-=(q*m);
			m=m/k;
		}	
	}
}

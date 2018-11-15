#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,i;	cin>>n;
		long long int A[n],B[n],C[n];
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>B[i];
		}
		for(i=0;i<n;i++)
		{
			C[i]=A[i]%B[i];
		}
		long long int max=-1;
		for(i=0;i<n;i++)
		{
			if(max<C[i])	max=C[i];
		}
		long long int ans=0;
		for(i=0;i<n;i++)	ans+=(max-C[i]);
		cout<<ans<<endl;
	}
}

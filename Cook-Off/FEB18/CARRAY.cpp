#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
	int n,k,b,i;	cin>>n>>k>>b;
	int A[n];	
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A,A+n);
	int m=A[0];
	int ans=1;
	for(i=1;i<n;i++)
	{
		if(A[i]>=k*m + b)
		{
			ans++;
			m=A[i];
		}	
	}
	cout<<ans<<endl;
	}
}

#include<bits/stdc++.h>
#define int long long int 
#define POW pow(2,31)
using namespace std;
main()
{
	int n,q,i,j,k;	cin>>n>>q;
	int A[n+1],B[n+1][32];
	for(i=1;i<=n;i++)	cin>>A[i];
	A[0]=0;
	for(i=0;i<=n;i++)
	{
		int temp=A[i];
		int p=POW;
		for(k=0;k<32;k++)
		{
			if(p<=temp)
			{
				B[i][k]=1;
				temp-=p;
			}
			else	B[i][k]=0;
			p/=2;
		}
	}
	for(i=0;i<=31;i++)
	{
		for(j=1;j<=n;j++)
		{
			B[j][i]+=B[j-1][i];
		}
	}
	while(q--)
	{
		int l,r;	cin>>l>>r;
		int ans=0;
		int p=POW/2;
		for(i=1;i<=31;i++)
		{
			int num=B[r][i]-B[l-1][i];
			if(num*2<(r-l+1))	ans+=p;
			p/=2;
		}
		cout<<ans<<endl;
	}
}

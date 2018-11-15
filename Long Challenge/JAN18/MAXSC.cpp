#include<bits/stdc++.h>
using namespace std;
long long int A[1000][1000];
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,i,j,ans=0,m;	cin>>n;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>A[i][j];
		for(i=0;i<n;i++)
			sort(A[i],A[i]+n);
		ans=A[n-1][n-1];
		m=ans;
		for(i=n-2;i>=0;i--)
		{
			bool flag=false;
			for(j=n-1;j>=0;j--)
			{
				if(A[i][j]<m)
				{
					ans+=A[i][j];
					m=A[i][j];
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				ans=-1;
				break;
			}
		}
		cout<<ans<<endl;
	}
}

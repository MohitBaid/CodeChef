#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;	cin>>n>>m>>k;
	int ans[n][m];
	int st = 0;
	int c = 1,i,j;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int t;
			cin>>t;
		}
	}*/
	if(k>n)
	{
		int diff = k-n;
		for(st=0;st<diff;st++)
		{
			for(j=0;j<m;j++)
			{
				if(j == ceil(m/2))
					c++;
				ans[st][j]=c;
			}
			c++;
		}
	}
	else if(k<n)
	{
		int diff = n-k;
		for(st = 0;st<diff;st++)
		{
			for(j=0;j<m;j++)
			{
				ans[st][j]=c;
			}
		}
		//c++;
	}
	for(;st<n;st++)
	{
		for(j=0;j<m;j++)
		{
			ans[st][j]=c;
		}
		c++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

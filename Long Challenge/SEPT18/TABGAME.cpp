#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int i,j,q=0;
		string col,row;
		cin>>col>>row;
		//cin>>q;
		
		int m = col.size(),n=row.size();
		int dp[n+1][m+1];
		
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				dp[i][j] = 0;
		
		for(i=1;i<=m;i++)		dp[0][i] = col[i-1]-'0';
		for(j=1;j<=n;j++)		dp[j][0] = row[j-1]-'0';
		
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				dp[i][j]=!(dp[i-1][j]&dp[i][j-1]);
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<dp[x][y];
		}
		cout<<endl;	
		
	}
}

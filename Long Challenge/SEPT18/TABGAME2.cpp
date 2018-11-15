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
		int A[n+1],B[m+1],dp[n+1][m+1];
		
		A[1]=row[0]-'0';
		B[1]=col[0]-'0';
		
		for(i=2;i<=n;i++)		A[i] = !(A[i-1]&(row[i-1]-'0'));
		for(i=2;i<=m;i++)		B[i] = !(B[i-1]&(col[i-1]-'0'));
		
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
		
		cout<<endl;
		for(i=1;i<=n;i++)	cout<<A[i]<<" ";	cout<<endl;
		for(i=1;i<=m;i++)	cout<<B[i]<<" ";	cout<<endl;
		
		/*while(q--)
		{
			int x,y;
			cin>>x>>y;
			if(A[x]==1 && B[y]==1)	cout<<"0";
			else					cout<<(A[x]|B[x]);
		}
		cout<<endl;*/	
		
	}
}

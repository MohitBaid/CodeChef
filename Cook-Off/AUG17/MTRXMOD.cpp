#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,i,j,k;	cin>>n>>q;
	int B[n+2][n+2],A[1005]={0};
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>B[i][j];
	for(i=0;i<=n;i++)	A[i]=-1000000;		A[1]=0;		
	for(k=1;k<=n/2;k++)		
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				int temp;
				temp=abs(A[i]-B[i][j]);
				if(A[j]<temp)
					A[j]=temp;
			}
	for(i=1;i<=n;i++)		cout<<A[i]*-1<<" ";	cout<<endl;
	while(q--)
	{
		int p;	cin>>p;
		for(i=1;i<=n;i++)
		{
			int temp;
			cin>>temp;	
			B[p][i]=B[i][p]=temp;
		}
		/*for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
					cout<<B[i][j]<<" ";
		cout<<endl;	*/		
		for(k=1;k<=n/2;k++)		
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				int temp;
				temp=abs(A[i]-B[i][j]);
				if(A[j]<temp)
					A[j]=temp;
			}
		for(i=1;i<=n;i++)		cout<<A[i]*-1<<" ";	cout<<endl;	
	}	
}

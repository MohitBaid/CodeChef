#include<bits/stdc++.h>
using namespace std;
int D[1000][1000];
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int x[n],y[n];
		for(i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}	
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				D[i][j]=sqrt((x[j]-x[i])*(x[j]-x[i]))+sqrt((y[j]-y[i])*(y[j]-y[i]));
			
		
}

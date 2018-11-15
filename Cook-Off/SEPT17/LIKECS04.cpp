#include<bits/stdc++.h>
using namespace std;
int A[101][101];
int main()
{
	int n,i,j,k;	cin>>n;
	int B[n];
	for(i=0;i<n;i++)	cin>>B[i];
	for(i=0;i<n;i++)
	{
		for(j=1;j<=100;j++)
		{
			for(k=0;k<=B[i];k++)
			{
				if(k%j==0)
				{
					A[i][j]++;
				}	
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		cout<<"---- For -----"<<B[i]<<endl;
		for(j=0;j<n;j++)
		{
			cout<<j<<" "<<A[i][j]<<endl;
		}
	}
	long long int alp=1;
}

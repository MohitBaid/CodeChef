#include<bits/stdc++.h>
using namespace std;
int A[501][100005];
int B[501][100005];
void compute()
{
	int i,j,k;
	for(j=0;j<=100000;j++)	A[1][j]=1;
	for(j=0;j<=500;j++)		A[j][1]=(j*(j+1))/2;
	for(i=2;i<=500;i++)
	{
		for(j=1;j<=100000;j++)
		{
			A[i][j]=(j+1)*(A[i-1][j]) - j +1;
			/*A[i][j]+=B[i-1][j-1];
			B[i][j]=B[i-1][j]+A[i][j];*/
		}
	}
}
int main()
{
	compute();
	int n,k;
	for(n=1;n<=10;n++)
		for(k=1;k<=10;k++)
			cout<<n<<","<<k<<":"<<A[n][k]<<endl;
}

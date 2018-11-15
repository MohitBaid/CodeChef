#include<bits/stdc++.h>
using namespace std;
int A[101][1000001]={0};
int main()
{
	int T;
	long long int i,j,k;	
	for(i=1;i<=100;i++)
	{		
		for(j=0;j<=1000000;j++)
		{	
			k=(j*j*j)%(i*i*i);			
			A[i][k]=1;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		long long int k,c;	scanf("%lld %lld",&k,&c);
		long long int temp=(k*k*k)-c;
		if(A[k][temp]==1||c==0)		printf("YES\n");
		else						printf("NO\n");
	}
}

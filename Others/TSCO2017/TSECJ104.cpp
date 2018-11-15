#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int A[n],i,j,B[n];
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(i=n-1;i>=0;i--)
		{
			B[i]=0;
			for(j=i;j>=0;j--)
			{
				if(A[j]>A[i])	break;
				B[i]++;
			}
		}
		for(i=0;i<n;i++)
			printf("%d ",B[i]);
		printf("\n");		
	}
}

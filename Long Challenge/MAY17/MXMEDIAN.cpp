#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		int A[2*n];
		for(i=0;i<2*n;i++)
			scanf("%d",&A[i]);
		sort(A,A+2*n);
		printf("%d\n",A[n+n/2]);
		for(i=0;i<n;i++)
			printf("%d %d ",A[i],A[i+n]);
		printf("\n");	
	}
}

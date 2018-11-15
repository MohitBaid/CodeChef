#include<stdio.h>
#include<algorithm>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int i,j,A[n];
		for(i=n;i>=1;i--)
			A[n-i]=i;
		int m=n/2;	
			for(i=m;i<(m+n);i++)
			{
				int k=0;
				for(j=i;k<n;j--)
				{
						printf("%d ",A[(n+j)%n]);
						k++;	
				}	
				printf("\n");
			}		
	}
}


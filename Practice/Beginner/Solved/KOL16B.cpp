#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		int m=1;
		while(T--)
		{
				int n,i;	scanf("%d",&n);
				int A[n],B[n];
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				for(i=0;i<n;i++)
				{
					B[i]=A[i]>>16;
					A[i]=A[i]-(B[i]<<16);
				}
				printf("Case %d:\n",m);
				for(i=0;i<n;i++)
					printf("%d ",A[i]);
				printf("\n");
				for(i=0;i<n;i++)
					printf("%d ",B[i]);
				printf("\n");	
				m++;	
		}
}

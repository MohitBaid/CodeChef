#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,temp;
		scanf("%d %d",&n,&m);
		int A[n];
		int ind[n-m];
		for(i=0;i<n;i++)
		{
				A[i]=0;
			if(i<n-m)
				ind[i]=0;
		}			
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			A[temp-1]=1;
		}
		temp=0;
		for(i=0;i<n;i++)
		{
			if(A[i]==0)
			{
				ind[temp]=i+1;
				temp++;
			}		
		}	
		for(i=0;i<n-m;i=i+2)
			printf("%d ",ind[i]);
		printf("\n");
		for(i=1;i<n-m;i=i+2)
			printf("%d ",ind[i]);
		printf("\n");			
	}
	return 0;
}

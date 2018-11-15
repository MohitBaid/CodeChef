#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
		int n,i,j;	scanf("%d",&n);
		int A[n];
		for(i=0;i<n;i++)
		{
			int s=0;
			for(j=0;j<n;j++)
			{
				scanf("%d",&A[j]);
				if(j<=n/2)
					s+=A[i];
			}
			std::sort(A,A+n);			
			for(j=0;j<n;j++)
					printf("%d ",A[j]);
				printf("\n");	
		}
}

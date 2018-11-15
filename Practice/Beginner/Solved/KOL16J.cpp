#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i,flag=1,c=0,sum=0;	scanf("%d",&n);
				int A[n];
				for(i=0;i<n;i++)
				{
						scanf("%d",&A[i]);
						if(A[i]-1==i)
							c++;
						sum+=A[i];	
				}
				if(c==n)
					printf("no\n");
				else
				{
						if(sum==n*(n+1)/2)
							printf("yes\n");
						else
							printf("no\n");	
				}		
		}
}

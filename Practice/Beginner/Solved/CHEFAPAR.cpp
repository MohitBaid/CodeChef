#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		long long int ans=n*1100;
		int A[n],i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			if(i==0)
			{
				if(A[i]==1)
				{
					//printf("Decreamenting 1100-----%d\n",i);
					ans-=1100;
				}
			}		
			else
			{
				if(A[i]==1)
				{
					if(A[i-1]==1)
					{
						//printf("Decreamenting 1100-----%d\n",i);
						ans-=1100;
					}	
					else
					{
						//printf("Decreamenting 1000-----%d\n",i);
						ans-=1000;	
						A[i]=0;
						A[i-1]=1;			
					}		
				}
			}	
		}		
		printf("%lld\n",ans);
	}
}

#include<stdio.h>
int gcd(int n1, int n2)
{
    if (n2!=0)
       return gcd(n2, n1%n2);
    else 
       return n1;
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,ans=0;	scanf("%d",&n);
		int A[n],S[n];
		for(i=0;i<n;i++)
		{
				scanf("%d",&A[i]);
				S[i]=0;
		}
		int s=0;			
		for(i=1;i<n;i++)
		{
			//printf("Comparing %d----%d\n",A[s],A[i]);
			if(gcd(A[i],A[s])!=1)
			{
					//printf("Changing both.....\n");
					S[s]=1;
					S[i]=1;
					s=i;		
			}
			else
			{	
				if(S[s]==0)		
					s=i;
			}		
										
		}
		for(i=0;i<n;i++)
			if(S[i]==1)
					ans++;
		printf("%d\n",ans);	
	}
}

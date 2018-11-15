#include<stdio.h>
#include<stdlib.h>
long long int gcd(int n1, int n2)
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
		int n;	scanf("%d",&n);
		long long int A[n],B[n],i=1,j,k;
		long long int ans=1000000000000000000;
		for(j=0;j<n;j++)
			scanf("%lld",&A[j]);	
		for(k=0;k<n;k++)
			{
				for(j=k+1;j<n;j++)
				{
					if(A[k]<A[j])
							i=gcd(A[k],A[j]);
					else
							i=gcd(A[j],A[k]);	
					i=A[k]*A[j]/i;			
					if(i<ans)
						ans=i;
				}	
			}
		printf("%lld\n",ans);		
	}	
}

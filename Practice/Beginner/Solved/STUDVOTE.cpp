#include<stdio.h>
int main()
{
	int T,n,k,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		int A[n];
		int B[n];
		int res=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			B[i]=0;
		}	
		for(i=0;i<n;i++)
		{
			if(A[i]==i+1)
				B[A[i]-1]=-999999;
			else
				B[A[i]-1]++;
		}
		for(i=0;i<n;i++)
		{	
			if(B[i]>=k)
				res++;	
		}
		printf("%d\n",res);		
	}
	return 0;
}

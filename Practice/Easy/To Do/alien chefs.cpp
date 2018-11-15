#include<stdio.h>
int main()
{
	int N;	scanf("%d",&N);
	int S[N],E[N],B[N];
	for(int i=0;i<N;i++)
			scanf("%d %d",&S[i],&E[i]);
	int Q;	scanf("%d",&Q);
	while(Q--)
	{
		int n;	scanf("%d",&n);
		int A[n];
		int t=0;
		for(int i=0;i<N;i++)
				B[i]=0;						
		for(int i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			for(int j=0;j<N;j++)
			{
				if(A[i]>=S[j]&&A[i]<=E[j]&&B[j]==0)
				{
						t++;
						B[j]=1;
				}	
			}
		}
		printf("%d\n",t);
	}		
	return 0;
}

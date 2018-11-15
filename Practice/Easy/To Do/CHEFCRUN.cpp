#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int s1=0,s2=0;int s,e,i;
		int N;	scanf("%d",&N);
		int A[N];
		for(i=0;i<N;i++)
			{
				scanf("%d",&A[i]);
				s1=s1+A[i];
			}
		scanf("%d %d",&s,&e);
		s--;
		e--;
		for(i=s;i<e;i++)	
			s2+=A[i];
		s1-=s2;
		printf("%d %d",s1,s2);	
		int D[N-s-e-1];
		int temp=0;int j=0;
		for(i=e-1;i>=0;i--,j++)
			{
				temp+=A[i];
				D[j]=temp;
			}
		for(i=N;i>s;i--,j++)
			{
				temp+=A[i];
				D[j]=temp;
			}
			printf("\n");
		for(i=0;i<=j;i++)
			printf("%d ",D[i]);	
				
	}
	return 0;
}

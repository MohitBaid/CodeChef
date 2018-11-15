#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;	scanf("%d",&n);
		long long int A[n];
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		long long int min=1000000000,temp;
		qsort(A,n,sizeof(long long int),cmpfunc);
		for(i=1;i<n;i++)
		{
			temp=A[i]-A[i-1];
			if(temp<0)
				temp=temp*-1;
			if(min>temp)
				min=temp;	
		}
		printf("%d\n",min);	
	}	
}

#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int  main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,k,i;	scanf("%d",&n);
		long long int A[n],key;
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		scanf("%d",&k);
		key=A[k-1];
		qsort(A,n,sizeof(long long int),cmpfunc);
		for(i=0;i<n;i++)
			if(A[i]==key)
			{
				printf("%d\n",i+1);
				break;
			}		
	}
}

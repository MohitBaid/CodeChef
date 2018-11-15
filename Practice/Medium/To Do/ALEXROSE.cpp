#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b == 0 )
        return 0;
}
int main()
{
	int t;	scanf("%d",&t);
	while(t--)
	{		
		int n,k,i;	scanf("%d %d",&n,&k);
		long long int A[n];
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		qsort(A,n,sizeof(long long int),cmpfunc);
		int q=n/k;
		for(i=1;i<n;i++)
		{
			if(A[i]!=A[i-1])
					q--;
			if(q==0)	break;		
		}
		printf("%d\n",n-i);
	}
}

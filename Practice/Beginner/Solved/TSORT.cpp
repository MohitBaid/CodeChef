#include<stdio.h>
#include<stdlib.h>
int A[1000000];
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++)
		scanf("%d",&A[i]);
	qsort(A,t,sizeof(int),cmpfunc);
	for(i=0;i<t;i++)
	{
		printf("%d\n",A[i]);
	}	
	return 0;
}

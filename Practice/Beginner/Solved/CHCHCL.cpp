#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int m,n,c=0;
		scanf("%lld %lld",&m,&n);
		c=m*n-1;
		if(c%2==0)
			printf("No\n");
		else
			printf("Yes\n");	
	}	
	return 0;
}

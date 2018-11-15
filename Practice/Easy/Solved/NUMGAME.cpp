#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int n;	scanf("%lld",&n);
		if(n%2==0)
			printf("ALICE\n");
		else
			printf("BOB\n");			
	}
	return 0;
}

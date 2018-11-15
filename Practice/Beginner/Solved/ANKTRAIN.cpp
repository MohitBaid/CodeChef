#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int f=n%8;
		if(f==0)		printf("%dSL\n",n-1);
		else if(f==1)	printf("%dLB\n",n+3);
		else if(f==2)	printf("%dMB\n",n+3);
		else if(f==3)	printf("%dUB\n",n+3);
		else if(f==4)	printf("%dLB\n",n-3);
		else if(f==5)	printf("%dMB\n",n-3);
		else if(f==6)	printf("%dUB\n",n-3);
		else if(f==7)	printf("%dSU\n",n+1);	
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int c,d,l;
		scanf("%lld %lld %lld",&c,&d,&l);
		if(c==0&&d==0&&l==0)
			printf("yes\n");
		else if(l==0||l%4!=0)
			printf("no\n");
		else if(l<=4*(c+d))
		{
			int n=l/4;		//no. of cats + dogs
			int nc=n-d;
			if(c>=nc&&c<=nc+2*d&&nc>=0)		
				printf("yes\n");
			else 
				printf("no\n");
		}
		else
			printf("no\n");	
			
	}
}

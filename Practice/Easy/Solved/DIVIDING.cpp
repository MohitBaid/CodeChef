#include<stdio.h>
int main()
{
		int n,t,s1;	scanf("%d",&n);
		s1=n*(n+1)/2;
		while(n--)
		{
				scanf("%d",&t);
				s1-=t;
		}
		if(s1==0)
			printf("YES\n");
		else
			printf("NO\n");	
}

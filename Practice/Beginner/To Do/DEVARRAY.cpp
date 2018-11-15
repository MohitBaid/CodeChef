#include<stdio.h>
int main()
{
		int n,q,i;	scanf("%d %d",&n,&q);
		int max=-1;
		int min=1000000000;
		int t;
		for(i=0;i<n;i++)
		{
				scanf("%d",&t);
				if(min>t)
					min=t;
				if(max<t)
					max=t;	
		}
		while(q--)
		{
				scanf("%d",&t);
				if(t<=max && t>=min)
					printf("YES\n");
				else
					printf("NO\n");	
		}
}

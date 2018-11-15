#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,n;
		scanf("%d %d %d %d",&n,&a,&b,&c);
		int i,j,k,ans=0;
		for(i=0;i<=a;i++)
			for(j=0;j<=b;j++)
					if(i+j<=n)
					{
						int d=n-(i+j);
						if(d<c)
							ans=ans+d+1;
						else
							ans=ans+c+1;	
						
						//printf("%d %d %d\n",i,j,k);
					}	
		printf("%d\n",ans);
	}						
}

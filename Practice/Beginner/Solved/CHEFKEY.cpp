#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int m,n,c,i,j,ans=0,flag;	scanf("%d %d %d",&n,&m,&c);
		for(i=1;i*i<=c;i++)
		{
			flag=0;
			if(c%i==0)
			{
				j=c/i;
				if(i<=n)
					{
						if(j<=m)
						{
							ans++;
							flag=1;
						}	
					}		
				if(i<=m)
					{
						if(j<=n)
							ans++;
					}
				if(i==j&&flag==1)
					ans--;						
			}
		}
		printf("%d\n",ans);
	}
}

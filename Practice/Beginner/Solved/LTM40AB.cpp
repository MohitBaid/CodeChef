#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				long long int a,b,c,d,ans=0,i;	
						scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
				for(i=a;i<=b;i++)
				{
						if(i<c)
							ans+=d-c+1;
						else if(i>=c &&i <=d)
							ans+=d-i;	
				}
				printf("%lld\n",ans);		
		}
}

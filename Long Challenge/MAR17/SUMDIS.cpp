#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n;	scanf("%d",&n);
				int temp;
				unsigned long long int ans=0;
				for(int i=1;i<n;i++)
				{
					scanf("%d",&temp);
					//printf("Adding---- %d*(%d-%d)*%d\n",i,n,i,temp);
					ans+=(i*(n-i)*temp);
				}
				for(int i=2;i<n;i++)
					scanf("%d",&temp);
				for(int i=3;i<n;i++)
					scanf("%d",&temp);
				printf("%I64d\n",ans);
		}
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,k;	scanf("%d %d",&n,&k);
		int i;int flag=0;
		int C[1000000]={0};
		int A[1000000]={0};
		for(i=1;i<=n;i++)
		{
				int p;	scanf("%d",&p);
				flag=0;
				while(p--)
				{
					int temp;	scanf("%d",&temp);
					if(C[temp]==0)
					{
						C[temp]++;
						flag=1;
					}
				}
				if(flag)
					A[i]=1;			
		}
		/*for(i=1;i<=k;i++)
			printf("%d ",C[i]);
		printf("\n");	
		for(i=1;i<=n;i++)
			printf("%d ",A[i]);
		printf("\n");*/
		flag=0;
		for(i=1;i<=k;i++)
		{
			if(C[i]==0)
			{
				printf("sad\n");
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			int flag2=0;
			for(i=1;i<=n;i++)
			{
				if(A[i]==0)
				{
					printf("some\n");
					flag2=1;
					break;
				}
			}
			if(!flag2)
				printf("all\n");
		}
	}
}

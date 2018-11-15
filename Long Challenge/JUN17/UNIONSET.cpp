#include<bits/stdc++.h>
using namespace std;
int A[2501][2501];
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,k,i,ans=0,j,l;	scanf("%d %d",&n,&k);
		for(i=0;i<=2500;i++)
			for(j=0;j<=2500;j++)
				A[i][j]=0;
		int B[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&B[i]);
			for(j=0;j<B[i];j++)
			{
				int temp;
				scanf("%d",&temp);
				A[i][temp]=1;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					int flag=0;
					for(l=1;l<=k;l++)
					{
						if(A[i][l]==0)
							if(A[j][l]==0)
							{
								flag=1;
								break;
							}	
					}	
					if(flag==0)
						ans++;
				}
			}
		}
		printf("%d\n",ans/2);
	}
}

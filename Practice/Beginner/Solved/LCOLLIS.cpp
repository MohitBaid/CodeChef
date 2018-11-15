#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,j,c1,col=0;
		scanf("%d %d",&n,&m);
		int A[n][m];
		char str[m];
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(j=0;j<m;j++)
					A[i][j]=str[j]-48;
		}			
		for(i=0;i<m;i++)
		{
			c1=0;
			for(j=0;j<n;j++)
			{
				if(A[j][i]==1)
					c1++;	
			}	
			col+=(c1*(c1-1))/2;
		}
		printf("%d\n",col);	
	}
	return 0;
}

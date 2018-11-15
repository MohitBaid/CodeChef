#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,j;	cin>>n>>m;
		int A[n][m],B[n][m],C[10][10]={0};
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>A[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				cin>>B[i][j];
				C[i][j]=B[i][j];
			}
		i=0,j=0;
		int temp=A[n-1][m-1];
		int pi1=0,pi2=0,pj1=0,pj2=0,c1=0,c2=0;
		while(1)
		{
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
				{
					pi1=i-1;
					pj1=j;
					pi2=i;
					pj2=j-1;
					if(pi1>=n||pj1>=m||pi1<0||pj1<0)		c1=10000;
					else									c1=A[pi1][pj1];
					if(pi2>=n||pj2>=m||pi2<0||pj2<0)						c2=10000;
					else									c2=A[pi2][pj2];
					if(c1<c2  || (c1==c2 && B[pi2][pj2]<B[pi1][pj1]))
					{
						A[i][j]=c2+A[i][j];
						C[i][j]+=B[pi2][pj2];
					}
					if(c1>c2  || (c1==c2 && B[pi2][pj2]>B[pi1][pj1]))
					{
						A[i][j]=c1+A[i][j];
						C[i][j]+=B[pi1][pj1];
					}
				}
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					printf("%d ",A[i][j]);	
				printf("\n");
			}
			if(temp==A[n-1][m-1])					break;
			else
			{
				for(i=0;i<n;i++)
					for(j=0;j<m;j++)
						C[i][j]=0;
			}	
		}
		printf("%d %d\n",A[n-1][m-1],C[n-1][m-1]);
	}
}

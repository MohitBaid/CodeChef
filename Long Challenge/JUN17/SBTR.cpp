#include<bits/stdc++.h>
using namespace std;
int AD[10000][10000];
int main()
{
	int n,m,i;	scanf("%d %d",&n,&m);
	int A[n],max=0,p=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]>max)
			max=A[i],p=i;
	}
	while(m--)
	{
		int u,v;	scanf("%d %d",&u,&v);
		AD[u-1][v-1]=1;
		AD[v-1][u-1]=1;
	}
	for(i=0;i<n;i++)
	{
		if(i!=p)
			printf("%d ",i+1);
	}
}

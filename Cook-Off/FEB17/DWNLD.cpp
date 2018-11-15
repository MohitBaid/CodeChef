#include<stdio.h>
int main()
{
	int TC;	scanf("%d",&TC);
	while(TC--)
	{
		int n,k,i;	scanf("%d %d",&n,&k);
		int T[n];
		int D[n];
		int cost=0;
		int f=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&T[i],&D[i]);
		}
	//	printf("%d----\n",f);
		for(i=0;i<n;i++)
		{
			f=f+T[i];
			//printf("%d----\n",f);
			if(f>k)
				break;
		}
		int p=(f-k)*D[i];
		//printf("%d----\n",p);
		i++;
		for(;i<n;i++)
			cost+=T[i]*D[i];
		printf("%d\n",cost+p);					
	}
}

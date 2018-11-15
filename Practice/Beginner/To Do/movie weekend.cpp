#include<stdio.h>
struct mov
{
	int L;
	int R;
	int pro;
}
int  main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int max=0;
		struct mov[n];
		for(i=0;i<n;i++)
			scanf("%d",&mov[i].L);
		for(i=0;i<n;i++)
		{
			scanf("%d",&mov[i].R);
			mov[i].pro=mov[i].L*mov[i].R;	
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
		}	
}

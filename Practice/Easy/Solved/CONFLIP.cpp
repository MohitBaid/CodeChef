#include<stdio.h>
int  main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int G;	scanf("%d",&G);
		while(G--)
		{
			int I,Q;
			long long int n;
			long long int h,t;
			scanf("%d %lld %d",&I,&n,&Q);
			if(I==1)
			{
				h=n/2;
				t=n-h;
			}
			else
			{
				t=n/2;
				h=n-t;
			}
			if(Q==1)
				printf("%lld\n",h);
			else
				printf("%lld\n",t);	
		}
	}
	return 0;
}

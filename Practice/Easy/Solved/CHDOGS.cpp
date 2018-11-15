#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int s,v;	scanf("%d %d",&s,&v);
		double ans=2.0*s/(3.0*v);
		printf("%lf\n",ans);
	}
	return 0;
}

#include<stdio.h>
int  main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==0||b==0||c==0)
		{
			printf("NO\n");
			continue;
		}
		if(a+b+c==180)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;
}

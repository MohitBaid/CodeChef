#include<stdio.h>
int main()
{
	int T,ans=0;	scanf("%d",&T);
	while(T--)
	{
		int x0,y0,x1,y1,x2,y2;
		scanf("%d %d %d %d %d %d",&x0,&y0,&x1,&y1,&x2,&y2);
		int a,b,c;
		a=((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1)); 	
		b=((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		c=((x0-x2)*(x0-x2) + (y0-y2)*(y0-y2));
		if(c==(a+b) || b==(a+c) ||a==(b+c))
			ans++;
	}	
	printf("%d\n",ans);
}

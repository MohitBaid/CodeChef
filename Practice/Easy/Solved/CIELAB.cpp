#include<stdio.h>
int main()
{
		int a,b,c;	scanf("%d %d",&a,&b);
		c=a-b;
		if(c%10==9)
			printf("%d\n",c-1);
		else
			printf("%d\n",c+1);	
}

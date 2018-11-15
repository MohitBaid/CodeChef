#include<stdio.h>
int main()
{
	int T,i;	scanf("%d",&T);
	while(T--)
	{
		int c0=0;int c1=0;
		char str[100000];
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]==48)
				c0++;
			else
				c1++;	
		}		
		if(c0==1||c1==1)
			printf("Yes\n");
		else
			printf("No\n");	
	}
}

#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char str[52];
		int check[26]={0},i,l,flag=1;
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
				check[str[i]-'a']++;		
		l=i;
		int max=check[0];
		for(i=0;i<26;i++)
		{
			if(check[i]>max)
				max=check[i];
		}
		if(max*2==l)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;
}

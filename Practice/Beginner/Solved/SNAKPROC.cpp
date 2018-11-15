#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		char c[n+2];	scanf("%s",c);
		int ch=0;
		int flag=0;
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='H')
			{
				if(ch==1)
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
					ch=1;
				}	
			}
			if(c[i]=='T')
			{
				if(ch==0)
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
					ch=0;
				}
			}
		}
		if(ch==0)
		{
			if(flag)		printf("Invalid\n");
			else			printf("Valid\n");
		}
		else				printf("Invalid\n");
	}
}

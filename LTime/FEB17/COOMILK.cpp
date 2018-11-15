#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
		int T;scanf("%d",&T);
		while(T--)
		{
				int n,flag=1;	scanf("%d",&n);
				char ch[20];	scanf("%s",ch);
				n--;
				while(n--)
				{
					char ch2[20];	scanf("%s",ch2);
					if(strcmp(ch,"cookie")==0)
					{
						if(strcmp(ch2,"cookie")==0)
						{
							flag=0;
						}
					}
					strcpy(ch,ch2);
					strcpy(ch2,"");				
				}
				if(strcmp(ch,"cookie")==0)
						flag=0;
				if(flag)
						printf("YES\n");
				else
						printf("NO\n");
	}
}

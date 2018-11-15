#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch[100];
		scanf("%s",ch);
		int d=0,u=0,flag,i;char c;
		for(i=0;ch[i]!='\0';i++)
		{
			if(i==0)
			{
				c=ch[i];
				if(c=='D')
					flag=0;
				else flag=1;
			}
			else
			{
				if(ch[i]==c);
				else
				{
					c=ch[i];
					if(flag)
					{
						u++;
						flag=0;
					}
					else
					{
						d++;
						flag=1;
					}	
				}
			}		
		}
		if(flag)	u++;
		else		d++;
		if(u<d)	printf("%d\n",u);
		else	printf("%d\n",d);	
	}
}

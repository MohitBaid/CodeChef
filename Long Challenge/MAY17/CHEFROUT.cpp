#include<bits/stdc++.h>
using namespace std;
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			char ch[100005];	scanf("%s",ch);
			int l,i,fe=0,fs=0,c=0;
			for(l=0;ch[l]!='\0';l++);
			for(i=0;ch[i]!='\0';i++)
			{
				if(ch[i]=='E')		fe=1;
				if(ch[i]=='S')		fs=1;
				if(ch[i]=='C')
				{
					if(fs==0&&fe==0)
							c++;
					else
							break;		
				}
				if(ch[i]=='E')
				{
					if(fs==0)
							c++;
					else
							break;		
				}
				if(ch[i]=='S')
						c++;	
			}
			if(c==l)
				printf("yes\n");
			else
				printf("no\n");	
		}
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		char ch[1000005],ch1[1000005];		cin>>ch1;
		int i,ans=0,c=0;
		for(i=0;ch1[i]!='\0';i++)
		{
			if(ch1[i]=='=');
			else	ch[c++]=ch1[i];
		}
		ch[c]=ch1[i],c=0;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]=='>')
			{	
				while(ch[i]=='>')
					c++,i++;
				i--;
			}
			if(ch[i]=='<')
			{
				while(ch[i]=='<')
					i++,c++;
				i--;
			}
			if(c>ans)	ans=c;
			c=0;
		}
		printf("%d\n",ans+1);
	}
}

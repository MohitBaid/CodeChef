#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch[150005],ch2[1500005];
		scanf("%s",ch);
		int i,j,flag,ans=0;
		while(1)
		{
			ans++;
			for(i=0;ch[i]!='\0';i++)
				ch2[i]=ch[i];
			for(i=0;ch[i]!='\0';i++)
			{
				for(j=0;ch[j]!='\0';j++)
				{
					int d=ch[i]-ch[j];
					if(d>0)
					{
						int g=abs(i-j);
						if(d>=g)
							ch2[j]=ch[i];
					}
				}
			}
			for(i=0;ch[i]!='\0';i++)
				cout<<ch2[i];
			cout<<endl;	
			for(i=0;ch[i]!='\0';i++)
				ch[i]=ch2[i];
				
			ch[i]='\0';
			flag=1;
			for(i=1;ch[i]!='\0';i++)
			{
				if(ch[i]!=ch[i-1])
					flag=0;
			}
			if(flag)
				break;
		}
		printf("%d\n",ans);
	}
}

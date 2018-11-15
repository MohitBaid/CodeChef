#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,ans=0,m=0;	scanf("%d",&n);
		char ch1[n+2],ch2[n+2];
		char ch3[n+2],ch4[n+2];
		scanf("%s",ch1);
		scanf("%s",ch2);
		for(i=0;i<n;i++)
		{
			if(ch1[i]=='.' && ch2[i]=='.');
			else
			{
				ch3[m]=ch1[i];
				ch4[m++]=ch2[i];
			}
		}
		ch3[m]='\0';
		ch4[m]='\0';
		int f1=0,f2=0;
		for(i=0;i<m;i++)
		{
			if(ch3[i]=='*')				f1=1;
			if(ch4[i]=='*')				f2=1;
		}
		if(f1==0&&f2==0)				printf("0\n");
		else if(f1==1 && f2==0)
		{
			for(i=0;ch1[i]!='\0';i++)
				if(ch1[i]=='*')
					ans++;
			printf("%d\n",ans-1);		
		}
		else if(f2==1 && f1==0)
		{
			for(i=0;ch2[i]!='\0';i++)
				if(ch2[i]=='*')
					ans++;
			printf("%d\n",ans-1);	
		}
		if(f1==1&&f2==1)				
		{
			ans++;
			int c=m-1;	
			for(i=0;i<m-1;i++)
			{	
				if(ch3[i]=='.' && ch3[i+1]=='*')
					if(ch4[i]=='*' && ch4[i+1]=='.')
					{
						c--;
						ch4[i+1]='*';
					}
				if(ch3[i]=='*' && ch3[i+1]=='.')
					if(ch4[i]=='.' && ch4[i+1]=='*')
					{
						c--;
						ch3[i+1]='*';
					}
				//cout<<c<<endl;			
			}
			printf("%d\n",ans+c);
		}
	}
}

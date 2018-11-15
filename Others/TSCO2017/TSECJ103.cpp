#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt.txt","r",stdin);
	int T;	scanf("%d",&T);
	while(T--)
	{
		char s1[1003],s2[1003];int n;
		cin>>s1>>s2>>n;
		n=n+1;
		int flag=0;
		while(n--)
		{
			char s[1003];	fgets(s,sizeof s,stdin);
			s[strlen(s)-1]='\0';
			//cout<<s<<endl;
			int p1=0,p2=0;
			int temp=1,i;
			for(i=0;s[i]!='\0';i++)
			{
				if(s[i]==s1[p1]&& s[i]==s2[p2])
				{
					char c=s[i+1];
					if(c==s1[p1+1])
					{
						i++;
						p1=p1+2;
					}
					else
					{
						i++;
						p2=p2+2;
					}
				}
				else if(s[i]==s1[p1])	p1++;
				else
				{
					if(s[i]==s2[p2])	p2++;
					else
					{
						temp=0;
						break;
					}
				}
			}
			if(temp)
			{
				if(s1[p1]=='\0'&&s2[p2]=='\0');
				else		temp=0;
			}
			if(temp&flag)		printf("YES\n");
			else if(!temp&&flag) 			printf("NO\n");
			flag=1;
		}
	}
}

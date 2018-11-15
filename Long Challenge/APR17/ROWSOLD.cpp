#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char s[1000005];
		scanf("%s",s);
		int i;
		int n1=0;
		long long int ans=0;
		long long int c=0;	
		long long int f=0;	
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='1')
			{					
				ans+=(c*f);
				if(c!=0)
					ans+=f;
				c=0;
				f++;			
			}
			else
				c++;
		}
		ans+=(c*f);
		if(c!=0)
			ans+=f;
		printf("%lld\n",ans);
	}
}

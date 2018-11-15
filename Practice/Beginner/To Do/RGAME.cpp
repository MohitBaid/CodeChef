#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int beg,end,ans,temp;
		scanf("%d",&temp);
		beg=temp;
		scanf("%d",&temp);
		end=temp;
		ans=beg*end;
		n=n-1;
		while(n--)
		{
			scanf("%d",&temp);
			if(temp*end>temp*beg)
			{
				ans+=temp*end;
				end=temp;
				ans=ans%MOD;
			}
			else
			{
				ans+=temp*beg;
				beg=temp;
				ans=ans%MOD;
			}
		}
		printf("%d\n",ans);
	}
}

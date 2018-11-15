#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int i=0,ans=0;
		for(i=0;i<n;i++)
		{
			int temp;	scanf("%d",&temp);
			if(temp>ans)
				ans=temp;
		}
		ans=n-ans;
		printf("%d\n",ans);
	}
}

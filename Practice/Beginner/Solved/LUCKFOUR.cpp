#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int ans=0;
		while(n>0)
		{
			if(n%10==4)
				ans++;
			n=n/10;
		}
		printf("%d\n",ans);
	}
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		int ans=n%10;
		while(n>=10)
		{
			n=n/10;
		}
		ans+=n;
		printf("%d\n",ans);
	}
}

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
			ans=ans*10+n%10;
			n=n/10;
		}
		printf("%d\n",ans);
	}
}

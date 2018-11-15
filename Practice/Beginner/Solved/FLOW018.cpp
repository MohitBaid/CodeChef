#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i;	scanf("%d",&n);
		long long int ans=1;
		for(i=1;i<=n;i++)
			ans=ans*i;
		printf("%lld\n",ans);		
	}
}

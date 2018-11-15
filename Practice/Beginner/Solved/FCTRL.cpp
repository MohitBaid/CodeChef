#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n;	scanf("%d",&n);
		long long int p=5,ans=0;;
		int m=1;
		while(1)
		{
			int fac=n/p;
			if(fac==0)
				break;
			ans+=(fac);
			p=p*5;
		}	
		printf("%lld\n",ans);
	}
}

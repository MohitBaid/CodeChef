#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int U,V;	scanf("%d %d",&U,&V);
		long long int ans;
		long long int x=U+V;
		ans=x*(x+1)/2;
		ans+=(U+1);
		printf("%lld\n",ans);
	}
}

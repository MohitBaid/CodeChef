#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,n;	scanf("%lld %lld %lld",&a,&b,&n);
		if(n%2)
			a=a*2;	
			if(a>b)
				printf("%lld\n",a/b);
			else
				printf("%lld\n",b/a);	
	}	
}

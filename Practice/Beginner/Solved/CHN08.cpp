#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int mod(long long int a)
{
	a=a%MOD;			
	if(a<0)
		a=a+MOD;
	return a;	
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;	scanf("%lld %lld",&a,&b);
		long long int n;		scanf("%lld",&n);
		n=n%6;
		if(n==0)		printf("%lld\n",mod(a-b));
		if(n==1)		printf("%lld\n",mod(a));
		if(n==2)		printf("%lld\n",mod(b));
		if(n==3)		printf("%lld\n",mod(b-a));
		if(n==4)		printf("%lld\n",mod(-1*a));
		if(n==5)		printf("%lld\n",mod(-1*b));
	}
}

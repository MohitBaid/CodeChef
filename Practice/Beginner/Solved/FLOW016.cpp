#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;	scanf("%lld %lld",&a,&b);
		long long int lcm=a*b;
		//printf("%lld\n",lcm);
		cout<<__gcd(a,b)<<" "<<setprecision(0)<<fixed<<(lcm/__gcd(a,b))<<endl;
	}
}

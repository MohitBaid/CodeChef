#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,ans=0,i,q,f,temp,t;
	scanf("%lf",&n);
	if(n<=39)
	{
		for(i=1;i<=n;i=i+1)
				ans+=floor(exp(1)*i);
	}
	else
	{
		ans=0;
		f=floor(exp(1)*39);
		for(i=40;i<=110;i=i+1)					ans+=floor(exp(1)*i);
		temp=ans-71*f;							ans=0;
		for(i=1;i<=39;i++)						ans+=floor(exp(1)*i);
		q=(n-39)/71;
		q=floor(q);			
		t=n-71*q;
		if(q)
			ans+=(71*((q)*f +(((q)*(q-1))/2)*(193)) +(q)*(temp));
		for(i=71*q+39+1;i<=n;i++)
			ans+=floor(exp(1)*i);	
	}
	printf("%.0lf\n",ans);
}

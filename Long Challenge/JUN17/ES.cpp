#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,ans=0,i,q,f,t;
	scanf("%lf",&n);
	ans=(2*n)+3*(n*(n-1)/2);
	if(n>=4)
	{
		n=n-3;
		q=n/7.0;
		q=floor(q);
		f=n-7*q;
		ans-=(4*q*q + 3*q*(q+1));
		if(f<=4)
		{
			t=2*q+1;
			ans-=(f*t);
		}
		else
		{
			t=2*q+1;
			ans-=(f*t);
			f=f-4;
			ans-=f;
		}
	}
	printf("%.0lf",ans);
}

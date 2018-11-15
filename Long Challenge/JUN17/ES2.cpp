#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n2,n,ans=0,i,j,ans2=0,q,f,t,temp;
	scanf("%lf",&n2);
	for(j=1;j<=n2;j=j+1)
	{
		ans=0;
		ans2+=floor(exp(1)*j);
		n=j;
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
			t=n-71*q-39;
			if(q)
				ans+=(71*((q)*f +(((q)*(q-1))/2)*(193)) +(q)*(temp));
			for(i=n;t>0;i--,t--)
				ans+=floor(exp(1)*i);
			if(q>=7)
			ans-=(q-6);	
			if(q>=15)
			ans-=(q-14);
			if(q>=22)
			ans-=(q-21);
			if(q>=29)
			ans-=(q-28);
			if(q>=36)
			ans-=(q-35);				
		}
		if(ans!=ans2 )
		{
			printf("----   %.0lf %.0lf %.0lf ----   %.0lf %.0lf \n",j,ans,ans2,q,t);	
		}	
		if(j==535)
		{
			printf("----   %.0lf %.0lf %.0lf ----\n",j,ans,ans2);	
		}
	}
}

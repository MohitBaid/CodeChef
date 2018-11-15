#include<bits/stdc++.h>
#define int long long int
#define MOD 1000000007
using namespace std;
int F[100];
int P[100];
int fp=0;
int power(int a,int n,int m)
{
	if(n==0)	return 1;
	if(n==1)	return (a%m);
	
	int temp = power(a,n/2,m);
	int ans =( temp * temp )%m;
	
	if(n%2 == 1)	
		ans= (ans * a)%m;
		
	return ans;
}
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int a,b,n,i,j;	cin>>a>>b>>n;
		int d = abs(a-b);
		if(d == 0)
		{
			cout<<(power(a,n,MOD) + power(b,n,MOD))<<endl;
			continue;
		}
		if(d%2 == 0)
		{
			int p = 0;
			while(d%2 == 0)
			{
				d = d/2;
				p++;
			}
			F[fp] = 2;
			P[fp++] = p;
		}
		for(i=3;i<=ceil(sqrt(d));i = i+2)
		{
			if(d==1)	break;
			
			if(d % i == 0)
			{
				int p = 0;
				while(d%i == 0)
				{
					d =d /i;
					p++;
				}
				F[fp] = i;
				P[fp++] = p;
			}
		}
		
		if(d != 1)	F[fp]=d,P[fp++]=1; 
		int ans = 1;
		
		for(i=0;i<fp;i++)
		{
			int pr = F[i];
			for(j=1; j<P[i]; j++)
			{
				pr = pr * F[i];
			}
			
			while(pr>1)
			{
				int pa = power(a,n,pr);
				int pb = power(b,n,pr);
				if( ( pa + pb )% pr == 0)
				{
					break;
				}
				pr = pr / F[i];
			}
			
			ans = ( ans * pr )%MOD;
		}
		
		cout<<ans<<endl;
		fp = 0;
	}
}

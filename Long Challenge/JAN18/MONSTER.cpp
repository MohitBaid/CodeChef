#include<bits/stdc++.h>
#define POW 134217728
using namespace std;
int C[262144];
int F[262144];
int g=0;
void sol(int n)
{
	int A[n+2],F[n+2],i,q;
	for(i=0;i<n;i++)	cin>>A[i],F[i]=1;
	cin>>q;
	int ans=n;
	while(q--)
	{
		int x,y;	cin>>x>>y;
		for(i=0;i<=min(x,n-1);i++)
		{
			if( ( i&x )==i)
			{
				if(F[i])
				{
					A[i]-=y;
					if(A[i]<=0)
					{
						ans--;
						F[i]=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
int gen(int i,char str[],int val,int n,int p)
{
	if(val>=n)	return 0;
	if(i==9)	
	{
		if(F[val]>0)
		{
			F[val]-=g;
			if(F[val]<=0)
				return 1;
		}
		return 0;
	}
	else
	{
		if(str[i]=='0')		return gen(i-1,str,val,n,p*2);
		else
		{
			return gen(i-1,str,val+p,n,p*2)+
			gen(i-1,str,val,n,p*2);
		}
	}
}
void cal(int n)
{
	int i,q,ans=n;
	for(i=0;i<n;i++)		cin>>F[i];
	cin>>q;
	while(q--)
	{
		int x,y;	cin>>x>>y;
		char str[28];
		int p=POW;
		for(i=0;i<=27;i++)
		{
			int f=x/p;
			str[i]=f+48;
			x-=(f*p);
			p=p/2;
		}
		x=0;
		p=1;
		for(i=0;i<18;i++)
		{
			if(str[27-i]=='1')
				x+=p;
			p=p*2;	
		}
		int h=gen(27,str,0,n,1);
		ans-=h;
		cout<<ans<<endl;
		h=0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;	cin>>n;
	if(n<=1024)		sol(n);
	else			cal(n);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000000007
long long int ans[2000005];
long long int anr[2000005];
long long int A[1000005];
int com(int n)
{
	int e=0,o=0,d;
	while(n)
	{
		d=n%10;
		if(d%2)	o+=d;
		else	e+=d;
		n=n/10;
	}
	return abs(o-e);
}
int main()
{
	ans[0]=0;
	ans[1]=1;
	int i,j;
	for(i=2;i<=2000004;i++)			ans[i]=com(i);
	anr[0]=ans[0];
	for(i=1;i<=2000004;i++)			
	{
		anr[i]=anr[i-1]+ans[i];
		anr[i]%=MOD;
	}
	A[0]=0;
	A[1]=ans[2];
	for(i=2;i<=1000004;i++)
	{
		A[i]=A[i-1];
		A[i]+=anr[2*i-1]-anr[i];
		A[i]%=MOD;
		A[i]+=anr[2*i-1]-anr[i];
		A[i]%=MOD;
		A[i]+=ans[2*i];
		A[i]%=MOD;
	}
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		cout<<A[n]<<endl;
	}
}

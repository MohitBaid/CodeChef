#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector < long long int > adj[100000];
long long int fib[100000];
long long int ans[100000];
long long int V[100000];
void fi(long long int a,long long int b,long long int k)
{
	fib[0]=a;
	fib[1]=b;
	int i;
	for(i=2;i<=k+3;i++)	
	{
		fib[i]=(fib[i-1]%MOD+fib[i-2]%MOD)%MOD;
		fib[i]%=MOD;
	}
}
void dfs(long long int i,long long int d,long long int k)
{
		V[i]=0;
		if(d<=k)
		{
			ans[i]=(ans[i]%MOD+fib[d]%MOD)%MOD;
			ans[i]%=MOD;
		}
		for(int it=0;it<adj[i].size();it++)
		{
			if(V[adj[i][it]]==1)
			{
				dfs(adj[i][it],d+1,k);
			}
		}
}
int main()
{
	long long int T,i;	cin>>T;
	while(T--)
	{
		long long int n,q,i;	cin>>n>>q;
		for(i=0;i<n;i++)	adj[i].clear(),ans[i]=0;
		for(i=0;i<n-1;i++)
		{
			long long int s,d;	cin>>s>>d;
			s--;	d--;
			adj[s].push_back(d);
			adj[d].push_back(s);
		}
		while(q--)
		{
			long long int ty;		cin>>ty;
			if(ty==1)
			{
				long long int v,k,a,b;	cin>>v>>k>>a>>b;
				v--;
				for(i=0;i<=n;i++)	V[i]=1;
				fi(a%MOD,b%MOD,k);
				dfs(v,0,k);
			}
			else
			{
				long long int v;	cin>>v;
				printf("%lld\n",ans[v-1]);
			}
		}
	}
}

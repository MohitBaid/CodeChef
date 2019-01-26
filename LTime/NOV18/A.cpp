#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
unordered_set < string > G;
void gen(string a,int n)
{
	if(a.size()==n)
	{
		G.insert(a);
	}
	else
	{
		gen(a+'0',n);
		gen(a+'1',n);
	}
}
main()
{
	int T;	cin>>T;
	vector < int > prime;
	
	for(int i=2;i<=1000;i++)
	{
		if(isprime(i) == 1 )
		{
			prime.push_back(i);
		}
	}
	
	while(T--)
	{
		int n,t;
		cin>>n;
		int A[n];
		vector < vector < int  > > v;
		v.resize(n);
		unordered_map < int,int > mp;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			
			for(int j1 =0;j1<prime.size();j1++)
			{
				int j = prime[j1];
				if(A[i]<j)	break;
				if(A[i]%j == 0)
				{
					v[i].push_back(j);
					while(A[i]%j==0)
						A[i]/=j;
				}
			}
			
			if(A[i]!=1)			v[i].push_back(A[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			int k = v[i].size();
			gen("",k);
			for(unordered_set < string > :: iterator st = G.begin();st!=G.end();st++)
			{
				int t = 1;
				string g = *st;
				for(int j=0;j<g.size();j++)
				{
					if(g[j]=='1')
						t = t*v[i][j];
				}
				if(t!=1)
					mp[t]++;
			}
			G.clear();
		}
		
		int ans = 0;
		for(unordered_map < int,int > :: iterator it = mp.begin();it!=mp.end();it++)
		{
			int m = it->first,k=0;
			for(int j = 0;j<prime.size();j++)
			{
				if(m<prime[j])	break;
				if(m%prime[j] == 0)	k++;
			}
			ans = max(ans,k*it->second);
		}
		cout<<ans<<endl;
	}
}

#include<bits/stdc++.h>
#define int long long int 
using namespace std;
vector < int > level [1005];
vector < int > :: iterator it,jt;
pair < int ,int > ans[1005];
int A[1050][1050]={0};
int B[1050][1050]={0};
int V[1050]={0};
int deg[1050]={0};
int lev=0;
void bfs(int u,int l,int n)
{
	level[l].push_back(u);
	V[u]=1;
	if(l>lev)	lev=l;
	for(int i=1;i<=n;i++)
	{
		if(A[u][i]>0)
		{
			if(V[i]==0)
				bfs(i,l+1,n);
		}
	}
}
main()
{
	int n,i;	cin>>n;
	for(i=0;i<n-1;i++)
	{
		int u,v,L;
		cin>>u>>v>>L;
		A[u][v]=L;
		A[v][u]=L;
		deg[u]++;
		deg[v]++;
	}
	int s=0;
	int val=10000;
	for(i=1;i<=n;i++)
	{
		if(deg[i]<val)
		{
			val=deg[i];
			s=i;
		}
	}
	bfs(s,0,n);
	int ml[n+1];
	for(i=0;i<lev;i++)
	{
		ml[i]=0;
		for(it=level[i].begin();it!=level[i].end();it++)
		{
			for(jt=level[i+1].begin();jt!=level[i+1].end();jt++)
			{
				if(ml[i]<A[*it][*jt])
					ml[i]=A[*it][*jt];
			}
		}
	}
	int x=0;
	for(i=0;i<=lev;i++)
	{ 
		int y=0;
		for(it=level[i].begin();it!=level[i].end();it++)
		{
			ans[(*it)]=make_pair(x,y);
			y++;
		}
		x+=ml[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}  


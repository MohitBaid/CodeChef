#include<bits/stdc++.h>
using namespace std;
int V[10000];
int B[10000];
int C[10000];
int D[10000];
int E[10000];
vector < vector < int > > v;
void bfs(int s)
{
	//cout<<"BFS "<<s<<endl;
	int i;
	V[s]=1;
	for(i=0;i<v[s].size();i++)
	{
		if(V[v[i][s]]==0)
		{
			bfs(v[i][s]);
		}
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		v.resize(n+2);
		for(i=1;i<=n;i++)
		{
			int t;	cin>>t;
			for(j=0;j<=n;j++)	D[j]=0,E[j]=0;
			for(j=0;j<t;j++)	cin>>B[j],D[B[j]]++;
			for(j=0;j<t;j++)	cin>>C[j],E[C[j]]++;
			
			//for(j=1;j<=n;j++)	cout<<D[j]<<" ";	cout<<endl;
			//for(j=1;j<=n;j++)	cout<<E[j]<<" ";	cout<<endl;
			
			for(j=1;j<=n;j++)
			{
				if(D[j]!=0 && E[j]!=0)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(i=1;i<=n;i++)	V[i]=0;
		/*for(i=1;i<=n;i++)
		{
			cout<<i<<":";
			for(j=0;j<v[i].size();j++)
			{
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		bfs(1);
		
		/*for(i=1;i<=n;i++)
		{
			if(V[i]==0)
				assert(0==1);
		}*/
		v.clear();
		v.resize(0);
		for(i=0;i<=n;i++)	V[i]=0,B[i]=0,C[i]=0,D[i]=0,E[i]=0;
		cout<<"0"<<endl;
	}
}

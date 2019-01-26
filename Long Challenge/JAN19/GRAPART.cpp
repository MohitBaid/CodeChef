#include<bits/stdc++.h>
using namespace std;
vector < vector < int > > adj;
vector < int > V;
vector < pair < int , int > > se[2];
void dfs(int s,int p)
{
	se[p].push_back(make_pair(adj[s].size(),s));
	V[s]=1;
	int i;
	for(i=0;i<adj[s].size();i++)
	{
		if(V[adj[s][i]]==0)
		{
			V[adj[s][i]] = 1;
			dfs(adj[s][i],(p+1)%2);
		}
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		adj.resize(n+1);
		V.resize(n+1);
		for(i=0;i<n-1;i++)
		{
			int s,d;	cin>>s>>d;
			adj[s].push_back(d);
			adj[d].push_back(s);
			V[i]=0;
		}
		V[n-1]=0;
		V[n]=0;
		dfs(1,0);
		sort(se[0].begin(),se[0].end());
		sort(se[1].begin(),se[1].end());
		if(se[0].size()==se[1].size())
		{
			cout<<"1"<<endl;
			for(i=0;i<se[0].size();i++)
				cout<<se[0][i].second<<" ";
			cout<<endl;
			
			for(i=0;i<se[1].size();i++)
				cout<<se[1][i].second<<" ";
			cout<<endl;	
		}
		else
		{
			cout<<"2"<<endl;
			if(se[0].size()>se[1].size())
			{
				int k = 0;
				for(i=0;i<se[1].size();i++)	
					cout<<se[1][i].second<<" ",k++;
				for(i=0;k<n/2;i++,k++)
					cout<<se[0][i].second<<" ";
				cout<<endl;		
			
				for(;i<se[0].size();i++)
					cout<<se[0][i].second<<" ";
				cout<<endl;
			}
			else
			{
				int k = 0;
				for(i=0;i<se[0].size();i++)	
					cout<<se[0][i].second<<" ",k++;
				for(i=0;k<n/2;i++,k++)
					cout<<se[1][i].second<<" ";
				cout<<endl;		
			
				for(;i<se[1].size();i++)
					cout<<se[1][i].second<<" ";
				cout<<endl;
			}
		}
		adj.clear();
		se[0].clear();
		se[1].clear();
	}
}

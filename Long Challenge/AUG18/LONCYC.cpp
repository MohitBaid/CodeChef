#include<bits/stdc++.h>
using namespace std;
int P[200000 + 10];
int C[200000 + 10];
int D[200000 + 10];
int V[200000 + 10];
int PO[200000 + 10];
int Cyc[200000 + 10];
int cy = 1;

vector < vector < int > > v;
void dfs(int s)
{
	int i;
	V[s]=1;
	for(i=0;i<v[s].size();i++)
	{
		if(V[v[s][i]]!=1)
		{
			P[v[s][i]] = s;
			if(C[s]==0)
				C[s] = v[s][i];
			dfs(v[s][i]);
		}
		else
		{
			if(v[s][i]!=P[s])
			{
				P[v[s][i]]=s,C[s]=v[s][i];
				int t = v[s][i];
				do
				{
					Cyc[t]=cy;
					t = P[t];
					
				}while((t != v[s][i]));
				cy++;
			}
		}
	}
}


void getPO(int s,int c)
{
	V[s]=1;
	if(PO[s]!=-1)	return ;
	if(D[s]==1 || (D[s]==3 && Cyc[s]!=0 && Cyc[s]!=c) || (D[s]==2 && Cyc[s] == c))	
	{
			PO[s]=0;
			return;
	}
	
	int temp=1,co=0;
	for(int i=0;i<v[s].size();i++)
	{
		if( V[v[s][i]] == 0 && Cyc[v[s][i]]!=c)
		{
			if(PO[v[s][i]]==-1)
				getPO(v[s][i],c);
			if(PO[v[s][i]] == 0)	co++;
			temp = temp * (PO[v[s][i]] + 1);
		}
	}
	if(temp == 1)		temp = co;
	else				temp += co; 
	PO[s] = temp;
}
int main()
{
	int T;	cin>>T;
	vector < pair < int,int > > edge;
	while(T--)
	{
		int n,m,i,j,k;	cin>>n>>m;
		v.resize(n+2);
		for(i=0;i<m;i++)
		{
			int s,d;	cin>>s>>d;
			v[s].push_back(d);
			v[d].push_back(s);
			D[s]++;		D[d]++;
			edge.push_back(make_pair(s,d));
		}	
		for(i=1;i<=n;i++)
		{
			cout<<i<<" :";
			for(j=0;j<v[i].size();j++)
			{
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
		P[1]=0;
		vector < int > temp;
		dfs(1);
		
		vector < vector < int > > ver;
		queue < int > que[cy+1];
		ver.resize(cy);
		for(i=1;i<=n;i++)
		{
			if(Cyc[i]!=0)
			{
				ver[Cyc[i]-1].push_back(i);
			}
		}
		
		vector < int > mark;
		for(i=0;i<cy;i++)
		{
			for(j=0;j<mark.size();j++)		V[mark[j]]=1;
			queue < int > q;
			for(j=0;j<ver[i].size();j++)	q.push(ver[i][j]);
			while(q.size())
			{
				int s = q.front();
				if(Cyc[s]==0 || Cyc[s] == i+1)
				{
					for(k=0;k<v[s].size();k++)
					{
						if(V[v[s][k]] == 1 && Cyc[v[s][k]]!= i+1)
						{
							ver[i].push_back(v[s][k]);
							q.push(v[s][k]);
							V[v[s][k]]=0;
							mark.push_back(v[s][k]);
						}
					}
				}
				else
				{
					for(k=0;k<v[s].size();k++)
					{
						if(V[v[s][k]] == 1 && Cyc[v[s][k]]!= Cyc[s] && Cyc[v[s][k]]!= i+1)
						{
							ver[i].push_back(v[s][k]);
							q.push(v[s][k]);
							V[v[s][k]]=0;
							mark.push_back(v[s][k]);
						}
					}
				}
				q.pop();
			}
		}
		for(j=0;j<mark.size();j++)	V[mark[i]]=1;	
		for(i=0;i<cy;i++)
		{
			for(j=0;j<ver[i].size();j++)	cout<<ver[i][j]<<" ",V[ver[i][j]]=0,PO[ver[i][j]]=-1;		cout<<endl;	
			for(j=0;j<ver[i].size();j++)
			{
				if(PO[ver[i][j]] == -1 && Cyc[ver[i][j]] == i+1)
				{
					getPO(ver[i][j],i+1);
				}
			}
			
			
			
			for(j=0;j<ver[i].size();j++)		cout<<ver[i][j]<<" "<<PO[ver[i][j]]<<endl;
			for(j=0;j<ver[i].size();j++)		PO[i]=-1,V[ver[i][j]]=1;	
			cout<<endl;
		}
		
		
		v.clear();
		for(i=0;i<200000 +10;i++)
		{
			P[i]=0,C[i]=0,D[i]=0,V[i]=0,PO[i]=0,Cyc[i]=0;
		}
	}
}

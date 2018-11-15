#include<bits/stdc++.h>
using namespace std; 
class Graph
{
public:
	list<long long int> *adj;
    long long int V;    
    Graph(long long int V);  
    void addEdge(long long int v, long long int w);
};
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list<long long int>[V];
}
void Graph::addEdge(long long int v, long long int w)
{
    adj[v].push_back(w); 
}
int main()
{
	long long int T,i;	cin>>T;
	while(T--)
	{
		long long int n,m;	cin>>n>>m;
		Graph g(n+2);
		for(i=0;i<m;i++)
		{
			long long int s,d;	cin>>s>>d;
			g.addEdge(s,d);
		}
		long long int A[n+2],temp=1;
		for(i=0;i<=n;i++)	A[i]=-1;
		list<long long int>::iterator it;
		set <long long int> s,p;
		set <long long int> ::iterator jt;
		for(it=g.adj[0].begin();it!=g.adj[0].end();it++)
		{
			s.insert(*it);	
		}
		temp=1;
		while(s.size()>0)
		{
			jt=s.begin();
			int t=*jt;
			s.erase(*jt);
			A[t]=temp;
			p.insert(temp);
			temp++;
		}
		for(i=1;i<=n;i++)
		{
			for(it=g.adj[i].begin();it!=g.adj[i].end();it++)
			{
				if(A[*it]==-1)		s.insert(*it);	
				else				p.erase(A[*it]);
			}
			while(s.size()>0)
			{
				jt=s.begin();
				int t=*jt;
				s.erase(*jt);
				jt=p.begin();
				A[t]=*jt;
				p.erase(*jt);
			}
			p.clear();
			for(it=g.adj[i].begin();it!=g.adj[i].end();it++)
			{
				if(A[*it]!=-1)					p.insert(A[*it]);	
			}
		}
		s.clear();
		long long int f=0;
		int flag=0;
		for(i=n;i>0;i--)
		{
			f+=s.size();
			s.insert(A[i]);
		}
		f+=s.size();
		if(f!=m)		flag=1;
		for(i=1;i<=n;i++)
			if(A[i]==-1)
				flag=1;
		if(flag)		cout<<"-1"<<endl;	
		else
		{
			for(long long int j=1;j<=n;j++)
				cout<<A[j]<<" ";
			cout<<endl;	
		}
	}
}

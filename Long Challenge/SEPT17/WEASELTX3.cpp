#include<bits/stdc++.h> 
using namespace std;
int L[1000000];
int P[1000000];
int check[1000000];
int S[1000000];
vector < vector <long long  int > > D;
int ans[1000000];
int len=0;
list<int> *adj;
class Graph
{
    int V;    
public:
    Graph(int V);  
    void addEdge(int v, int w); 
    void BFS(int s); 
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
	adj[w].push_back(v);
}
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
	int lev=0; 
	L[s]=lev;
	P[s]=-1;
    while(!queue.empty())
    {
		s = queue.front();
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                P[*i]=s;
				L[*i]=L[P[*i]]+1;
				queue.push_back(*i);
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,i,j;	cin>>n>>q;		
	Graph g(n+2);
	int A[n+2];
	for(i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.BFS(0);
	for(i=0;i<n;i++)	cin>>A[i];		
	list < int > :: iterator it;
	set < pair < int ,int > > s;
	set < pair < int ,int > > :: iterator jt;
	for(i=0;i<n;i++)									s.insert(make_pair(L[i]*-1,i));
	for(jt=s.begin(),i=0;jt!=s.end(),i<n;jt++,i++)		L[i]=jt->second;
	ans[len++]=A[0];
	D.resize(n);
	for(i=0;i<n;i++)	D[i].push_back(A[i]);
	int k=0;
	int ini=A[0];
	while(1)
	{
		k++;
		for(i=0;i<n;i++)
		{
			int t=L[i];
			if(check[t]==1)
			{
				int tem=k%S[t];
				A[t]=D[t][tem];	
			}
			else
			{
				int temp=A[t];
				for(it=adj[t].begin();it!=adj[t].end();it++)	if(*it!=P[t])	temp=temp^A[*it];
				A[t]=temp;
				if(A[t]==D[t][0])
				{
					S[t]=k;
					check[t]=1;
				}
				else	D[t].push_back(A[t]);
			}
		}	
		if(ini==A[0])	break;
		ans[len++]=A[0];	
	}
	//for(i=0;i<n;i++)		cout<<ans[i]<<" ";	cout<<endl;
	while(q--)
	{
		int t;	cin>>t;
		t=t%len;
		cout<<ans[t]<<endl;
	}
}

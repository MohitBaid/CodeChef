//http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
#include<bits/stdc++.h>
#include<list>
long long int A[1000][1000];
int m=0; 
using namespace std;
stack <int> s;
int lev[10001];
int m2=0;
class Graph
{
    int V;    
    list<int> *adj;    
    void DFSUtil(int v, bool visited[],int);  
public:
    Graph(int V);   
    void addEdge(int v, int w); 
    void DFS(int v,int);    
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
void Graph::DFSUtil(int v, bool visited[],int g)
{
	visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            s.push(*i);
            visited[*i]=true;
			lev[*i]=m2;
			m2++;
			DFSUtil(*i, visited,g);
			if(m2==lev[*i] && *i!=g)		s.pop();
		}
		if(*i==g)			return;
	}
	m2--;
}
void Graph::DFS(int v,int g)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    s.push(v);
	DFSUtil(v, visited,g);
}
int main()
{
    int T;	cin>>T;
    while(T--)
    {
    	int n;	cin>>n;
		Graph g(n);
		int e=n-1;
		while(e--)
		{
			long long int u,v,c;	cin>>u>>v>>c;	u--,v--;		
   			g.addEdge(u, v);
    		A[u][v]=c;	A[v][u]=c;
		}
    	int m1;	cin>>m1;
    	while(m1--)
    	{
    		long long int u,v,k;	cin>>u>>v>>k;	u--,v--;
    		g.DFS(u,v);
    		long long int ans=0,a=u;
    		int temp=s.top();
    		s.pop();
			while(s.size()>0)
    		{
				if(A[temp][s.top()]<=k)		ans=ans^A[temp][s.top()];
    			
				temp=s.top();
    			s.pop();
    		}
    		printf("%lld\n",ans);
    	}
	}
}

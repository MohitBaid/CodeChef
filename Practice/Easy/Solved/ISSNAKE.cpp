// C++ program to print connected components in
// an undirected graph
//http://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
#include<iostream>
#include <list>
using namespace std;
class Graph
{
 public:
    int V;    
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
    Graph(int V);   
    void addEdge(int v, int w);
    int connectedComponents();
};
int Graph::connectedComponents()
{
    bool *visited = new bool[V];
    int ans=0;
	for(int v = 0; v < V; v++)
        visited[v] = false;
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
			DFSUtil(v, visited);
    		ans++;
		}
	}
	return ans;
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
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
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,c=0;	scanf("%d",&n);
		char A[n+1],B[n+1];
		int m1[n],m2[n];
		for(i=0;i<n;i++)
			m1[i]=m2[i]=1;
		scanf("%s",A);
		scanf("%s",B);
		Graph g(2*n);
		for(i=0;i<n;i++)
		{
			if(A[i]=='#')
			{
				if(A[i+1]=='#')
					g.addEdge(i,i+1);
				if(B[i]=='#')
					g.addEdge(i,i+n);	
			}
			if(B[i]=='#')
			{
				if(B[i+1]=='#')
					g.addEdge(i,i+1);
				if(A[i]=='#')
					g.addEdge(i,i+n);	
			}
			if(A[i]=='.')
			{
				c++;
				/*if(A[i+1]=='.')
					g.addEdge(i,i+1);
				if(B[i]=='.')
					g.addEdge(i,i+n);	*/
			}
			if(B[i]=='.')
			{
				c++;		
				/*if(B[i+1]=='.')
					g.addEdge(i,i+1);
				if(A[i]=='.')
					g.addEdge(i,i+n);	*/
			}
		}
	   	for(i = 0; i < 2*n; i++)
			g.adj[i].unique();
		int m=g.connectedComponents();		
		cout<<m<<" "<<c<<endl;
		if(m-c==1)	printf("yes\n");
		else		printf("no\n");
	}
}

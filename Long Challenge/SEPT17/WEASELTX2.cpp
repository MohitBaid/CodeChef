#include<bits/stdc++.h>
using namespace std;
int L[1000000];
int P[1000000];
int start[1000000];
int end[1000000];
int DFSa[1000000];
int dfs;
list<int> *adj;
class Graph
{
    int V;    
public:
	void DFSUtil(int v, bool visited[]);
    Graph(int V);  
    void addEdge(int v, int w); 
    void BFS(int s); 
    void DFS(int v); 
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
        lev++;
		s = queue.front();
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                L[*i]=lev;
                P[*i]=s;
				queue.push_back(*i);
            }
        }
    }
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    start[v]=dfs++;
    list<int>::iterator i;
    bool f;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
    	f=false;
        if (!visited[*i])
        {
          	f=true;
		    DFSUtil(*i, visited);
        }
  	}
  	end[v]=dfs++;
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    //DFSa[dfs++]=v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,q,i,j;	cin>>n>>q;
	vector < long long int > ans,tem;
	set < vector <long long int > > se;
	Graph g(n+2);
	long long int A[n+2];
	for(i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.DFS(0);
	for(i=0;i<n;i++)
		cout<<start[i]<<" "<<end[i]<<endl;
	cout<<endl;
	//for(i=0;i<n;i++)	cin>>A[i],tem.push_back(A[i]);		
	//g.BFS(0);
	/*list < int > :: iterator it;
	set < pair < int ,int > > s;
	set < pair < int ,int > > :: iterator jt;
	
	for(i=0;i<n;i++)									s.insert(make_pair(L[i]*-1,i));
	for(jt=s.begin(),i=0;jt!=s.end(),i<n;jt++,i++)		L[i]=jt->second;
	int st=0;
	for(st=0;st<n;st++)
	{
		if(L[st]!=L[0])
			break;
	}
	ans.push_back(A[0]);
	se.insert(tem);
	tem.clear();
	//long long int k=20000000/n;
	while(1)
	{
		for(i=st;i<n;i++)
		{
			int t=L[i];
			long long int temp=A[t];
			for(it=adj[t].begin();it!=adj[t].end();it++)
			{
				temp=temp^A[*it];
			}
			if(P[t]!=-1)		temp=temp^A[P[t]];
			A[t]=temp;
		}		
		for(i=0;i<n;i++)				tem.push_back(A[i]);
		if(se.find(tem)==se.end())		se.insert(tem),tem.clear();
		else							break;
		ans.push_back(A[0]);
	}
	long long int len=ans.size();
	while(q--)
	{
		long long int t;	cin>>t;
		t=t%len;
		cout<<ans[t]<<endl;
	}*/
}

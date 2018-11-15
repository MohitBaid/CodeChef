#include<bits/stdc++.h>
using namespace std;
int L[1000000];
int P[1000000];
int S[1000000];
vector < vector <long long int > > D;
long long int ans[1000000];
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
	int n,q,i,j,lev=-1;	cin>>n>>q;		
	Graph g(n+2);
	long long int A[n+2];
	for(i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.BFS(0);
	for(i=0;i<n;i++)			if(L[i]>lev)	lev=L[i];		lev++;
	int C[lev+1],sum;
	long long int R[lev+1];
	for(i=0;i<n;i++)		cin>>A[i];		
	for(i=0;i<lev;i++)		R[i]=0;
	for(i=0;i<n;i++)		R[L[i]]=R[L[i]]^A[i];
	C[0]=1;
	for(i=1;i<lev;i++)		C[i]=0;
	ans[len++]=A[0];
	while(1)
	{
		sum=0;
		for(i=1;i<lev;i++)
		{
			C[i]+=C[i-1];
			C[i]=C[i]%2;
			sum+=C[i];
		}
		sum-=C[i-1];
		//for(i=0;i<lev;i++)		cout<<C[i]<<" ";	cout<<endl;
		if(sum)
		{
			ans[len]=0;
			for(i=0;i<lev;i++)		if(C[i])		ans[len]=ans[len]^R[i];
			len++;
		}
		else	
		{
			ans[len]=0;
			for(i=0;i<lev;i++)		if(C[i])		ans[len]=ans[len]^R[i];
			len++;
			break;
		}
	}
	while(q--)
	{
		long long int t;	cin>>t;
		t=t%((2*len)-1);
		if(t<len)		cout<<ans[t]<<endl;
		else			cout<<(ans[t-len+1]^R[lev-1])<<endl;
	}
}

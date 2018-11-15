//https://www.hackerearth.com/practice/notes/fast-io-optimization-in-c/
//http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
#include<bits/stdc++.h>
using namespace std;
int L[2000000];
int P[2000000];
int S[2000000];
int A2[100000];
long long int R[2000000];
long long int ans[2000000];
int ctr=0;
list<int> *adj;
void fastscan(int &x)
{
        register int c;
        x =0;
        c=getchar();
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
}
void fastscanL(long long int &x)
{
        register long long int c;
        x =0;
        c=getchar();
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
}
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
long long int getAns(int t,int s,int cycle,int lev)
{		
	if(ans[t]!=-1 && s==0)		return ans[t];
	if(cycle == 0)				return R[s];
	if(cycle == 1)				return R[s];
	else
	{
		cycle=cycle/2;
		if(t/cycle==1)
		{
			long long int t1=getAns(t-cycle,s,cycle,lev),t2=0;
			if(s+cycle<lev)		t2=getAns(t-cycle,s+cycle,cycle,lev);
			if(s==0 && ans[t-cycle]==-1)
			{
				ans[t-cycle]=t1;
			}
			return t1^t2;									//1 1
		}
		else
		{
			long long int t1=getAns(t,s,cycle,lev);
			if(s==0 && ans[t]==-1)
			{
				ans[t]=t1;
			}	
			return t1;									//1 0	
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,i,j,lev=-1,cycle=1,ctr=2;	
	cin>>n>>q;		
	Graph g(n+2);
	long long int A[n+2];
	for(i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.BFS(0);
	for(i=0;i<n;i++)		if(L[i]>lev)	lev=L[i];		lev++;
	for(i=0;i<n;i++)		cin>>A[i];		
	for(i=0;i<lev;i++)		R[i]=0;
	for(i=0;i<n;i++)		R[L[i]]=R[L[i]]^A[i];
	while(cycle<lev)		cycle=cycle*2,ctr++;
	for(i=0;i<cycle;i++)	ans[i]=-1;
	ans[0]=R[0];	
	A2[0]=0;	A2[1]=2;
	for(i=2;i<=cycle;i++)
		if(i>=A2[i-1])			A2[i]=A2[i-1]*2;
		else					A2[i]=A2[i-1];
	ctr=cycle/2;	
	for(i=cycle-1;ctr>0 && i>=0;i--)
	{
		ans[i]=getAns(i,0,A2[i],lev);
		ctr--;
	}	
	while(q--)
	{
		long long int t2;	cin>>t2;
		int t=(1LL*t2)%cycle;
		t=(cycle-t)%cycle;
		if(ans[t]!=-1)		cout<<ans[t]<<"\n";
		else
		{
			//ans[t]=getAns(t,0,A2[t],lev);
			cout<<ans[t]<<"\n";
		}
	}
}

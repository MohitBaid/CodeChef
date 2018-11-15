//from http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
// C++ program to print DFS traversal for a given given graph
#include<bits/stdc++.h>
using namespace std;
int p[100000];
int m;
class Graph
{
    int V;    
    list<int> *adj;    
    void DFSUtil(int v, bool visited[]);  
public:
    Graph(int V);   
    void addEdge(int v, int w);  
    void DFS(int s);    
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout<<v<<" "<<endl;
 	p[m++]=v;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
void Graph::DFS(int s)
{
    bool *visited = new bool[100000];
    for (int i = 1; i <= V; i++)
        visited[i] = false;
    for(int i=1;i<10005;i++)
		p[i]=-1;    	
	m=0;
    DFSUtil(s,visited);
    //cout<<"MMMMM"<<endl;
}
 
int main()
{
    // Create a graph given in the above diagram
    int N,Q,u,v,k,i,R,key,t; 
	cin >> N >> Q;
	cin >> R >> key;
	map <int,int> mp;
	map <int,int> set;
	int d=1;
	if(set[R]==0)
			set[R]=d++;
	mp[set[R]]=key;
	Graph g(300000);
	for (i = 0; i < N - 1; i++)
	{
    		cin >>u>>v>>k;
			if(set[u]==0)
				set[u]=d++;
			if(set[v]==0)
				set[v]=d++;	
			//cout<<u<<" "<<set[u]<<endl;
			//cout<<v<<" "<<set[v]<<endl;
			g.addEdge(set[u],set[v]);
			g.addEdge(set[v],set[u]);
			mp[set[u]]=k;
			
	}
	int last_answer = 0;
	for (i = 0; i < Q; i++)
	{
		cin >> t;
    	t ^= last_answer;
    	if (t == 0)
    	{
        	cin >> v >> u >> k;
			u ^= last_answer;
        	v ^= last_answer;
        	k ^= last_answer;
        	
    		//cin >>u>>v>>k;
			if(set[u]==0)
				set[u]=d++;
			if(set[v]==0)
				set[v]=d++;	
			g.addEdge(set[u],set[v]);
			g.addEdge(set[v],set[u]);
			mp[set[u]]=k;
			//cout<<u<<" "<<set[u]<<endl;
			//cout<<v<<" "<<set[v]<<endl;
		}
    	else
    	{
        	cin >> v >> k;
        	v ^= last_answer;
        	k ^= last_answer;
			g.DFS(set[v]);
			int min_answer=k^mp[p[0]];
        	int max_answer=k^mp[p[0]];
        	int temp1=0,temp2=0;
			for(int j=0;j<m;j++)
        	{
				temp1=k^mp[p[j]];
				if(temp1>max_answer)
					max_answer=temp1;
				if(temp1<min_answer)
					min_answer=temp1;	
				if(p[j]==set[R])
						break;	
			}
			cout<<min_answer<<" "<<max_answer<<endl;
			last_answer = min_answer ^ max_answer;  
    	}
    	//cout<<"\n\n"<<i<<"\n";
	}
    return 0;
}

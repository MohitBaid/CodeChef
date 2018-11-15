//https://www.hackerearth.com/practice/notes/fast-io-optimization-in-c/
//http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
#include<bits/stdc++.h>
using namespace std;
int L[2000000];
int P[2000000];
int S[2000000];
int A2[2000002];
long long int ans[2000000];
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,i,j,lev=-1;	
	fastscan(n);
	fastscan(q);
	//cin>>n>>q;		
	Graph g(n+2);
	long long int A[n+2];
	for(i=0;i<n-1;i++)
	{
		int u,v;
		fastscan(u);
		fastscan(v);
		//cin>>u>>v;
		g.addEdge(u,v);
	}
	g.BFS(0);
	for(i=0;i<n;i++)			if(L[i]>lev)	lev=L[i];		lev++;
	long long int R[lev+1];
	for(i=0;i<n;i++)		fastscanL(A[i]);	//*/cin>>A[i];		
	for(i=0;i<lev;i++)		R[i]=0;
	for(i=0;i<n;i++)		R[L[i]]=R[L[i]]^A[i];
	int cycle=1;
	long long int R2[lev+1];
	R2[0]=R[0];
	for(i=1;i<lev;i++)
	{
		R2[i]=0;
		R2[i]^=(R2[i-1] ^ R[i] );
	}
	//for(i=0;i<lev;i++)	cout<<R[i]<<" ";	cout<<endl;
	//for(i=0;i<lev;i++)	cout<<R2[i]<<" ";	cout<<endl;
	while(cycle<lev)		cycle=cycle*2;
	A2[0]=0;
	for(i=1;i<=262150;i++)
	{
		if(i%2==1)
		{
			A2[i]=A2[i-1];
		}
		else
		{
			int temp=i;
			int c=0;
			while(temp%2==0)
			{
				c++;
				temp=temp/2;
			}
			A2[i]=A2[i-1]+c;
		}
	}
	for(i=0;i<=cycle;i++)	ans[i]=-1;
	ans[0]=R[0];
	while(q--)
	{
		long long int t;	fastscanL(t);	//cin>>t;
		t=t%cycle;
		t=(cycle-t)%cycle;
		if(ans[t]!=-1)		printf("%lld\n",ans[t]);//cout<<ans[t]<<"\n";
		else		
		{
			ans[t]=0;
			if(!(t&(t+1)))
			{
				//cout<<R2[t]<<endl;
				if(t>=lev || t>n)	ans[t]=R2[lev-1];
				else				ans[t]=R2[t];
				printf("%lld\n",ans[t]);
			}
			else if(!(t&(t-1)))
			{
				int tem=t;
				int f=0;
				while(tem)
				{
					f++;
					tem/=2;
				}
				for(i=0;i<=t && i<lev;i=i+t)
				{
					ans[t]^=R[i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-2)&(t-1)))
			{
				for(i=0; i<=1 && i<lev ;i++)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-2)&(t-3)))
			{
				for(i=0; i<=2 && i<lev ;i=i+2)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-4)&(t-3)))
			{
				for(i=0; i<=3 && i<lev ;i++)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-4)&(t-5)))
			{
				for(i=0; i<=4 && i<lev ;i=i+4)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-6)&(t-5)))
			{
				for(i=0; i<=5 && i<lev ;i=i+4)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
					if(i+1<lev)
					{
						ans[t]^=R[i+1];
						if(t-i-1 < lev)	ans[t]^=R[t-i-1];
					}
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-6)&(t-7)))
			{
				for(i=0; i<=6 && i<lev ;i=i+2)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-8)&(t-7)))
			{
				for(i=0; i<=7 && i<lev ;i++)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-8)&(t-9)))
			{
				for(i=0; i<=8 && i<lev ;i=i+8)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-10)&(t-9)))
			{
				for(i=0; i<=8 && i<lev ;i=i+8)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
					if(i+1<lev)
					{
						ans[t]^=R[i+1];
						if(t-i-1 < lev)	ans[t]^=R[t-i-1];
					}
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-10)&(t-11)))
			{
				for(i=0; i<=8 && i<lev ;i=i+8)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
					if(i+2<lev)
					{
						ans[t]^=R[i+2];
						if(t-i-2 < lev)	ans[t]^=R[t-i-2];
					}
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-12)&(t-11)))
			{
				for(i=0; i<=3 && i<lev ;i++)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-12)&(t-13)))
			{
				for(i=0; i<=3 && i<lev ;i=i+3)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
				}
				printf("%lld\n",ans[t]);
			}
			else if(!((t-14)&(t-13)))
			{
				for(i=0; i<=3 && i<lev ;i=i+3)		
				{
					ans[t]^=R[i];
					if(t-i < lev)	ans[t]^=R[t-i];
					if(i+1<lev)
					{
						ans[t]^=R[i+1];
						if(t-i-1 < lev)	ans[t]^=R[t-i-1];
					}
				}
				printf("%lld\n",ans[t]);
			}
			
			else
			{
				for(i=0; i<=t/2 && i<lev ;i++)		
				{
					if(A2[t]<=A2[i]+A2[t-i])		
					{
						ans[t]^=R[i];
						if(t-i < lev)	ans[t]^=R[t-i];
					}
				}
				if(t%2==0 && t/2 < lev)
				{
					if(A2[t]<=2*A2[t/2])		
					{
						ans[t]^=R[i];
					}
				}
				printf("%lld\n",ans[t]);//cout<<ans[t]<<"\n";
			}
		}
	}
}

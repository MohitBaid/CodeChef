//http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
#include<bits/stdc++.h>
# define double long double
using namespace std;
#define INF 999999999999999999999999999999
double dist[50][50];
int P[50][50];
int iscube(double n)
{
	int root=round(cbrt(n));
	if(n==root*root*root)	return 1;
	return 0;
}
void floydWarshall (double graph[][50],long long int V)
{
    int i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] * dist[k][j] < dist[i][j]*graph[k][k])
                    dist[i][j] = dist[i][k] * dist[k][j] / graph[k][k],P[i][j]=P[i][k]+P[k][j];
                    
            }
        }
    }
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,i,j;	cin>>n;
		double G[50][50];
		double A[n];	
		for(i=0;i<n;i++)	cin>>A[i];
		for(i=0;i<50;i++)
			for(j=0;j<n;j++)
			{
				G[i][j]=INF;
				if(i==j)
					G[i][j]=A[i];
				P[i][j]=0;
			}
		//for(i=0;i<n;i++)	cout<<A[i]<<" ";	cout<<endl;	
		for(i=0;i<n-1;i++)
		{
			int s,d;	cin>>s>>d;
			s--;
			d--;
			G[s][d]=A[s]*A[d];
			G[d][s]=A[s]*A[d];
			P[s][d]++;
			P[d][s]++;
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<G[i][j]<<" ";
			printf("\n");	
		}
		cout<<endl<<endl;*/
		floydWarshall(G,n);
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<dist[i][j]<<" "<<P[i][j]<<"      ";
			printf("\n");	
		}*/
		int ans=-1;//,temp=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][j]!=-1 && iscube(dist[i][j]))
				{
					if(ans<P[i][j])
						ans=P[i][j];//,temp=dist[i][j];
				}
			}
		}
		if(ans!=-1)
			cout<<ans+1<<endl;//<<" "<<temp<<endl;
		else	cout<<-1<<endl;	
	} 
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k	;	cin>>n>>m;
	int A[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			A[i][j]=0;
	for(i=0;i<2*m;i++)
	{
		int x,y;	cin>>x>>y;
		A[x-1][y-1]=1;
	}
	int path = 0;
	vector < pair < int ,int > > v;
	for(i=0;i<n;i++)
	{
		if(i%2 == 0)
		{
			for(j=0;j<n;j++)
			{
				if(A[i][j] == 1)
				{
					if(path == 0)
					{
						path = 1;
					}
					else
					{
						cout<<v.size()+1<<" ";
						for(k=0;k<v.size();k++)
						{
							cout<<v[k].first+1<<" "<<v[k].second+1<<" ";
						}
						cout<<i+1<<" "<<j+1<<endl;
						v.clear();
						path = 0;
					}
				}
				if(path == 1)
					v.push_back(make_pair(i,j));
			}
		}
		else
		{
			for(j=n-1;j>=0;j--)
			{
				if(A[i][j] == 1)
				{
					if(path == 0)
					{
						path = 1;
					}
					else
					{
						cout<<v.size()+1<<" ";
						for(k=0;k<v.size();k++)
						{
							cout<<v[k].first+1<<" "<<v[k].second+1<<" ";
						}
						cout<<i+1<<" "<<j+1<<endl;
						v.clear();
						path = 0;
					}
				}
				if(path == 1)
					v.push_back(make_pair(i,j));
			}
		}
	}
}

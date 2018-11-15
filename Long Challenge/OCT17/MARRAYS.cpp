#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,i,j,k;	cin>>T;
	while(T--)
	{
		long long int ***P;
		long long int **A;
		long long int *s;
		long long int n;	cin>>n;
		P=(long long int ***)malloc(sizeof(long long int **)*n);
		A=(long long int **)malloc(sizeof(long long int*)*n);
		s=(long long int *)malloc(sizeof(long long int)*n);
		set < pair < long long int,long long int > > se;
		set < pair < long long int,long long int > >:: iterator it;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			A[i]=(long long int *)malloc(sizeof(long long int)*s[i]);
			for(j=0;j<s[i];j++)		cin>>A[i][j];
			long long int max=A[i][0],min=A[i][0];
			for(j=0;j<s[i];j++)
			{
				if(max<A[i][j])	max=A[i][j];
				if(min>A[i][j])	min=A[i][j];
			}
			for(j=0;j<s[i];j++)
			{
				if(i==0||i==n-1)
				{
					if(A[i][j]==min||A[i][j]==max)
					{
						se.insert(make_pair(A[i][j],A[i][(j+s[i]-1)%s[i]]));
						se.insert(make_pair(A[i][(j+1)%s[i]],A[i][j]));
					}
				}
				else
				{
					se.insert(make_pair(A[i][j],A[i][(j+s[i]-1)%s[i]]));
					se.insert(make_pair(A[i][(j+1)%s[i]],A[i][j]));
				}
			}
			P[i]=(long long int **)malloc(sizeof(long long int *)*se.size());
			j=0;
			for(it=se.begin();it!=se.end();it++)
			{
				P[i][j]=(long long int *)malloc(sizeof(long long int)*3);
				P[i][j][0]=it->first;
				P[i][j][1]=it->second;
				P[i][j][2]=0;
				j++;
			}
			s[i]=se.size();
			se.clear();
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<s[i];j++)
			{
				cout<<P[i][j][0]<<" "<<P[i][j][1]<<endl;
			}
			cout<<endl;
		}
		for(i=0;i<n;i++)		cout<<s[i]<<" ";	cout<<endl;*/
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<s[i];j++)
			{
				long long int ans=0;
				for(k=0;k<s[i+1];k++)
				{
					ans=max(ans,(i+1)*(abs(P[i][j][1]-P[i+1][k][0])) + P[i+1][k][2]);
				}
				P[i][j][2]=ans;
			}
		}
		long long int ans=0;
		for(i=0;i<s[0];i++)	
			ans=max(ans,P[0][i][2]);
		cout<<ans<<endl;	
	}
}

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		vector < pair <int,int>  > s;
		int n,m,i,j;	cin>>n>>m;
		long long int B[m+2],C[m+2],D[m+2];
		long long int A[n+2];
		for(i=0;i<=m+1;i++)	B[i]=0,C[i]=0,D[i]=0;
		for(i=0;i<=n+1;i++)	A[i]=0;
		for(i=1;i<=m;i++)
		{
			int c,l,r;	cin>>c>>l>>r;
			s.push_back(make_pair(l,r));
			if(c==1)
			{
				B[i]=0;
				A[l]++;
				A[r+1]--;
			}
			else
			{
				C[i]=-1;
				B[l]++;
				B[r+1]--;
			}
		}
		for(i=1;i<=m;i++)	B[i]+=B[i-1],B[i]=B[i]%MOD;
		//for(i=1;i<=m;i++)	printf("%d ",B[i]);	cout<<endl;
		for(i=m;i>=1;i--)
		{
			if(C[i]==-1)
			{
				//printf("%d\n",i);
				int l=s[i-1].first;
				int r=s[i-1].second;
				B[l-1]+=B[i];
				B[r+1]-=B[i];
				B[i]=0;
			}
			for(j=1;j<=m;j++)	cout<<B[j]<<" ";	cout<<endl;
		}
		for(i=2;i<=m;i++)	B[i]+=B[i]+B[i-1];//-B[i-2];	
		for(i=1;i<=m;i++)	printf("%d ",B[i]);	cout<<endl;
		for(i=1;i<=m;i++)
		{
			int l=s[i-1].first;
			int r=s[i-1].second;
			A[l]+=B[i];
			A[l]=A[l]%MOD;
			A[r+1]-=B[i];
			A[r+1]=A[r+1]%MOD;
		}
		for(i=1;i<=n;i++)	A[i]+=A[i-1],A[i]=A[i]%MOD;
		for(i=1;i<=n;i++)	cout<<A[i]%MOD<<" ";	cout<<endl;
	}
}

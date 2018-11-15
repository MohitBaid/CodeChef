#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
double B[100000+2],C[100000+2],D[100000+2];
double A[100000+2];
int main()
{
	double T;	cin>>T;
	while(T--)
	{
		vector < pair <double,double>  > s;
		double n,m;int i,j;	cin>>n>>m;
		
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
		for(i=1;i<=m;i++)	B[i]+=B[i-1];
		//for(i=1;i<=m;i++)	prdoublef("%d ",B[i]);	cout<<endl;
		for(i=1;i<=m;i++)
		{
			if(B[i]>MOD)
			{
				double q= B[i]/MOD;
				B[i]-=q*MOD;
			}
		}
		for(i=m;i>=1;i--)
		{
			if(C[i]==-1)
			{
				//prdoublef("%d\n",i);
				double l=s[i-1].first;
				double r=s[i-1].second;
				for(j=l;j<=r;j++)	B[j]+=B[i];
				B[i]=0;
			}
			//for(j=1;j<=m;j++)	cout<<B[j]<<" ";	cout<<endl;
		}
		//for(i=1;i<=m;i++)	prdoublef("%d ",B[i]);	cout<<endl;
		for(i=1;i<=m;i++)
		{
			int l=s[i-1].first;
			int r=s[i-1].second;
			A[l]+=B[i];
			A[r+1]-=B[i];
		}
		for(i=1;i<=n;i++)	A[i]+=A[i-1];
		for(i=1;i<=n;i++)
		{
			if(A[i]>MOD)
			{
				double q= A[i]/MOD;
				A[i]-=q*MOD;
			}
		}
		for(i=1;i<=n;i++)	cout<<(long long int)A[i]<<" ";	cout<<endl;
	}
}

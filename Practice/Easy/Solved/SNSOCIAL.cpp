#include<bits/stdc++.h>
using namespace std;
int check(int A[][500],int n,int m)
{
	set < int > s;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)	
			s.insert(A[i][j]);
	if(s.size()==1)	return 1;
	return 0;		
}
int change(int A[][500],int M[500][500],int i,int j,int n,int m,int max)
{
	int s=0;
	if(i!=0)
	{
		if(A[i-1][j]<max)					
		{
			A[i-1][j]=max;
			s++;
		}
		if(j!=0 && A[i-1][j-1]<max)	
		{	
			A[i-1][j-1]=max;
			s++;
		}
		if(j!=m-1 && A[i-1][j+1]<max)	
		{	
			A[i-1][j+1]=max;		
			s++;
		}
	}
	if(j!=0 && A[i][j-1]<max)		
	{		
		A[i][j-1]=max;
		s++;
	}
	if(j!=m-1 && A[i][j+1]<max)		
	{		
		A[i][j+1]=max;
		s++;
	}	
	if(i!=n-1)
	{
		if(A[i+1][j]<max)					
		{
			A[i+1][j]=max;
			s++;
		}
		if(j!=0 && A[i+1][j-1]<max)	
		{	
			A[i+1][j-1]=max;
			s++;
		}
		if(j!=m-1 && A[i+1][j+1]<max)	
		{	
			A[i+1][j+1]=max;		
			s++;
		}
	}
	M[i][j]=1;
	return s;
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,m,i,j;	scanf("%d %d",&n,&m);
		int A[500][500];
		int M[500][500]={0};
		int max=0,ans=0,s=0; 
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&A[i][j]);
				if(max<A[i][j])
					max=A[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				if(A[i][j]==max)
					s++;
		}
		while(1)
		{
			if(s==n*m)		break;
			else
			{
				vector < pair <int,int > > vec;
				for(i=0;i<n;i++)
					for(j=0;j<m;j++)
						if(A[i][j]==max && M[i][j]==0)
							vec.push_back(make_pair(i,j));
				vector < pair <int,int > > :: iterator it;
				for(it=vec.begin();it!=vec.end();it++)
				{
						int a=change(A,M,it->first,it->second,n,m,max);
						s+=a;
				}				
				ans++;
				if(s>=n*m)
					break;
			}
		}
		printf("%d\n",ans);
	}
}

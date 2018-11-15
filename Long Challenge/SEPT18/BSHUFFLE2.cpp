#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T=1;	//cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int A[n+1],B[n+1];
		for(i=1;i<=n;i++)	A[i]=i;
		
		
		B[1]=n/2 +1;
		int m = n;
		for(i=2;i<=n;i++)	
		{
			if(m==n/2 +1)	m--;
			B[i] = m;
			m--;
		}
		//B[n]=2;
		
		for(j=1;j<=n;j++)	swap(A[j],A[B[j]]);
		for(i=1;i<=n;i++)	cout<<A[i]<<" ";	cout<<endl;		
	
		for(i=1;i<=n;i++)	A[i]=i;
		for(j=1;j<=n;j++)	swap(A[j],A[1]);	
		for(i=1;i<=n;i++)	cout<<A[i]<<" ";	cout<<endl;	
	}
}

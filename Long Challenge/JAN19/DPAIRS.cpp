#include<bits/stdc++.h>
#define int long long int
#define map unordered_map
using namespace std;
main()
{
	int n,m,i,j,k=0;	cin>>n>>m;
	int A[n],B[m];
	map < int ,int > mp,mpA,mpB;
	for(i=0;i<n;i++)	
	{
		cin>>A[i];
		mpA[A[i]] = i;
	}
	for(i=0;i<m;i++)	
	{
		cin>>B[i];
		mpB[B[i]] = i;
	}
	sort(A,A+n);
	sort(B,B+m);
	bool ans = false;
	int x = 0;
	int y = 0;
	while(k<(m+n-1))
	{
		if(mp[ A[x] + B[y] ] == 0)
		{
			cout<<mpA[A[x]]<<" "<<mpB[B[y]]<<endl;
			mp[A[x] + B[y] ] =1;
			k++;
		}
		if(x+1<n && y+1<m)
		{
			if(A[x+1] <= B[y+1] )			x++;
			else							y++;	
		}
		else if(y+1 < m)		y++;
		else if(x+1 < n)		x++;
	}
}

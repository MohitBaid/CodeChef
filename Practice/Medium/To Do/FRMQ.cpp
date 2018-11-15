#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int n,i,j;	cin>>n;
	int A[n];

	for(i=0;i<n;i++)
		cin>>A[i];

	int S = ceil(sqrt(n));
	int B = ceil(n*1.0/S);
	int Max[B + 2];
	
	for(i=0;i<B;i++)
	{
		Max[i]=0;
		for(j=i*S;j<min(i*S+S,n);j++)
		{
			if(Max[i]<A[j])
			{
				Max[i]=A[j];
			}
		}
	}
	
	int M,x,y,final = 0;	cin>>M>>x>>y;
	
	while(M--)
	{
		
		int l = min(x,y);
		int r = max(x,y);
		int ans = 0;
		int sB = ceil(l*1.0/S);
		int eB = floor(r*1.0/S);
		for(i=l;i<=min((sB+1)*S,r);i++)
			if(A[i]>ans)
				ans = A[i];
				
		for(i=sB+1;i<=eB;i++)
			if(Max[i]>ans)
				ans = Max[i];
				
		for(i=max(l,eB*S);i<=r;i++)
			if(A[i]>ans)
				ans = A[i];
				
		final+=ans;					
		x = (x+7)%(n-1);
		y = (y+11)%n;		
	
	}
	cout<<final<<endl;		
}

#include<bits/stdc++.h>
#define int long long int 
using namespace std;
main()
{
	int n,q,i,j;	cin>>n;
	int x[n],y[n];
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	cin>>q;	
	while(q--)
	{
		int f,t;	cin>>f>>t;
		f--;
		t--;
		int ans = 0;
		for(i=f;i<=t;i++)
		{
			for(j=i+1;j<=t;j++)
			{
				int t = x[i]-x[j];
				t = t*t;
				t+=(y[i]-y[j])*(y[i]-y[j]);
				ans = max(t,ans);
			}	
		}	
		cout<<ans<<endl;
	}	
}

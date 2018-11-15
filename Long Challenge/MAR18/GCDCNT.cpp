#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,q;	cin>>n;
	int A[n];
	for(i=0;i<n;i++)	cin>>A[i];
	cin>>q;
	while(q--)
	{
		int ch;	cin>>ch;
		if(ch==1)
		{
			int x,val;	cin>>x>>val;
			A[x-1]=val;
		}
		else
		{
			int l,r,g,ans=0;	cin>>l>>r>>g;
			for(i=l-1;i<r;i++)
				if(__gcd(g,A[i])==1)	
					ans++;
			cout<<ans<<endl;
		}
	}
}

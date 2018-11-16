#include<bits/stdc++.h>
#define int long long int 
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,m,t,c=0;	cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>t;
			if(t%m == 0)
				c++;
		}
		int ans=pow(2,c)-1; 
		cout<<ans<<endl;
	}
}
		
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		long long int t,ans;
		cin>>t;
		ans=t;
		for(i=1;i<n;i++)
		{
			cin>>t;
			ans=__gcd(ans,t);
		}
		cout<<ans<<endl;
	}
}

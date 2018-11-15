#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,t;	cin>>n;
		long long int ans=n*(n-1)/2;
		while(n--)	cin>>t;	
		cout<<ans<<endl;
	}
}

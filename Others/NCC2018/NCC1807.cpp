#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,k;	cin>>n>>k;
		int ans=(n*(n+1))/2 +( n-1)*k;
		cout<<ans<<endl;
	}
}

#include<bits/stdc++.h>
#define int long long int 
#define MOD 1000000007
using namespace std;
main()
{
	int n,i;	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<((n-i)*(n-i))%MOD +i <<" ";
	}
}

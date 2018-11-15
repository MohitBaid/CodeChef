#include<bits/stdc++.h>
#define int long long int 
#define MOD 998244353
using namespace std;
main()
{
	int n,i;	cin>>n;
	int A[n];
	int C[n];
	for(i=0;i<n;i++)	cin>>A[i];
	for(i=0;i<n;i++)	cin>>C[i];
	int pos = -1;
	for(i=0;i<n;i++)
	{
		if(A[i] == C[1])
		{
			pos = i;
			break;
		}
	}
	assert(pos != -1);
	//assert((A[pos]*A[pos])%MOD==C[2]);
	for(i=0;i<n;i++)
	{
		if(i == pos)
			cout<<"1 ";
		else
			cout<<"0 ";
	}
	cout<<endl;
}

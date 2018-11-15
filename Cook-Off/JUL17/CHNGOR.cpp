#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		int A[n];
		int ans=0;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			ans=ans|A[i];
		}
		cout<<ans<<endl;
	}
}

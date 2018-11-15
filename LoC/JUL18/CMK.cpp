#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,k,i;	cin>>n>>k;
		int A[n],B[n];
		for(i=0;i<n;i++)	cin>>A[i];
		for(i=0;i<n;i++)	cin>>B[i];
		sort(A,A+n);
		sort(B,B+n);
		string ans = "YES";
		for(i=0;i<k;i++)
		{
			if(A[i]>B[n-1-i])
			{
				ans = "NO";
			}
		}
		cout<<ans<<endl;
	}
}

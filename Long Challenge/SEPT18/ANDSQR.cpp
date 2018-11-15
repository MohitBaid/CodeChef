#include<bits/stdc++.h>
#define int long long int
using namespace std;
bool isquare(int n)
{
	int k = sqrt(n);
	if(k*k == n)
		return true;
	else
		return false;	
}
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,q,j;	cin>>n>>q;
		int A[n];
		for(i=0;i<n;i++)	cin>>A[i];
		while(q--)
		{
			int l,r;	cin>>l>>r;
			l--;r--;
			int ans = 0;
			for(i=l;i<=r;i++)
			{
				int temp = A[i];
				if(isquare(temp))
					ans++;
				for(j=i+1;j<=r;j++)
				{
					temp = temp & A[j];
					if(isquare(temp))
						ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}

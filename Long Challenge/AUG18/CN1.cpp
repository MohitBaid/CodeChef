#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int n,k,d,i,j;	cin>>n>>k>>d;
	int R[k];
	int A[n][k];
	for(i=0;i<k;i++)	cin>>R[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			cin>>A[i][j];
		}
	}
	float ans = 10000000000.0;
	for(i=0;i<k;i++)
	{
		float avg = 0.0;
		for(j=0;j<n;j++)
		{
			avg +=A[j][i];
		}
		avg = avg*1.0/(n*1.0);
		//cout<<avg<<endl;
		float temp = 0.0;
		for(j=0;j<n;j++)
		{
			temp = temp + abs(avg - A[j][i]);
		}
		ans = min(ans,temp);
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int i,j;
	while(t--)
	{
		int n,b,c;
		cin>>n>>b>>c;
		long long arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		long long d,dist = 1e17;
		int ind;
		int val = arr[0];
		sort(arr,arr+n);
		long long gap[n-1];
		for(i=0;i<n-1;i++)
		{
			gap[i] = arr[i+1] - arr[i];
		}
		long long str = 0;
		for(i=0;i<n-b+1;i++)
		{
			for(j=0;j<n-i-2;j++)
			{
				d = gap[j+1]*gap[j+1] + gap[j]*gap[j] - gap[j] - gap[j+1];
				if(d<dist)
				{
					d = dist;
					ind = j;
				}
			}
			gap[j-1] += gap[j];
			str += gap[j];
			for(j=ind+1;j<n-i;j++)
			{
				gap[j-1] = gap[j];
			}
				
		}
		cout<<str<<endl;
	}
}

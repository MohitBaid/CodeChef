#include<bits/stdc++.h>
#define int long long int 
using namespace std;
main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int A[n],ans[n+1];
		vector < int > v1,v2;
		vector < int > :: iterator it;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			ans[i]=0;
		}
		ans[n]=0;
		int temp=0,sum=0;
		for(i=0;i<n;i++)
		{
			temp+=A[i];
			v1.push_back(temp);
		}	
		temp=0;
		for(i=n-1;i>=0;i--)
		{
			temp+=A[i];
			v2.push_back(temp);
			sum+=A[i];
		}
		for(i=0;i<n;i++)
		{
			it=upper_bound(v1.begin(),v1.end(),v1[i]+A[i]);
			if(it==v1.end())	it--;
			ans[i+1]++;	ans[(it-v1.begin()) +1]--;
			it=upper_bound(v2.begin(),v2.end(),v2[n-1-i]+A[i]);
			if(it==v2.end())	it--;		
			ans[n- (it-v2.begin())-1]++;	ans[i]--;
		}
		for(i=1;i<=n;i++)	ans[i]+=ans[i-1];
		for(i=0;i<n;i++)	cout<<ans[i]<<" ";	cout<<endl;
	}
}

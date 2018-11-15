#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,temp;	cin>>T;
	while(T--)
	{
		set < long long int >s;
		long long int n,k,size,te,i;	cin>>n>>k;
		for(i=0;i<n;i++)	
		{
			cin>>te;
			if(te!=0)
				s.insert(te);
		}
		long long int ans=0;
		for(i=0;i<k;i++)
		{
			te=pow(2,i);
			if(s.find(te)==s.end())	ans++;
			//te=te*1LL*2;
			//cout<<te<<endl;
		}
		cout<<ans<<endl;
	}
}

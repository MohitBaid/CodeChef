#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; 	cin>>T;
	while(T--)
	{
		int n,i,t;		cin>>n;
		int min=1000000,ans=-1;
		for(i=0;i<n;i++)
		{
			cin>>t;
			if(t<min)
			{
				min=t;
				ans=i;
			}
		}
		cout<<ans+1<<endl;
	}
}

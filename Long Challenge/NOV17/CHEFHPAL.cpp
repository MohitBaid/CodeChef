#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,a,i;	cin>>n>>a;
		if(a==1)		
		{
			cout<<n<<" ";
			for(i=0;i<n;i++)	cout<<"a";
			cout<<endl;
		}
		else if(a==2)
		{
			int af=ceil(n*1.0/2.0);
			cout<<af<<" ";
			for(i=0;i<af;i++)	cout<<"a";
			for(;i<n;i++)		cout<<"b";
			cout<<endl;
		}	
		else		
		{
			cout<<"1 ";
			string temp;
			for(i=0;i<a;i++)	temp+=(char)(97+i);
			string ans;
			int q=n/a;
			while(q--)	ans+=temp;
			q=n%a;
			for(i=0;i<q;i++)	ans+=temp[i];
			cout<<ans<<endl;	
		}
	}
}

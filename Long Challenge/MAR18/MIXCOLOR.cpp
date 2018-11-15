#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,t;	cin>>n;
		set < int  > s;
		for(i=0;i<n;i++)
		{
			cin>>t;
			s.insert(t);
		}
		cout<<n-s.size()<<endl;
	}
}

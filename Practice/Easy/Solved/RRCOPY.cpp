#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		set <int > s;
		for(i=0;i<n;i++)
		{
			int t;	cin>>t;
			s.insert(t);
		}
		cout<<s.size()<<endl;
	}
}

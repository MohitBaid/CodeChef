#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2,n3;	cin>>n1>>n2>>n3;
	map <int,int> mp;
	int n=n1+n2+n3;
	while(n--)
	{
		scanf("%d",&n1);
		mp[n1]++;
	}
	map <int,int> ::iterator it;
	set <int> s;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>=2)
			s.insert(it->first);
	}
	cout<<s.size()<<endl;
	set <int> ::iterator vt;
	for(vt=s.begin();vt!=s.end();vt++)
		cout<<*vt<<endl;
}

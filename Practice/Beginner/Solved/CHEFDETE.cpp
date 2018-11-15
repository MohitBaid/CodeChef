#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,t;	scanf("%d",&n);
	set < int > s;
	for(i=0;i<=n;i++)
		s.insert(i);
	set <int> ::iterator it;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		it=s.find(t);
		if(it!=s.end())
			s.erase(it);
	}	
	for(it=s.begin();it!=s.end();it++)
		printf("%d ",*it);
}

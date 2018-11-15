#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		set < int > s;
		set < int > :: iterator it;
		for(i=0;i<=3*100000;i++)
			s.insert(i);
		int n,k;	cin>>n>>k;	
		for(i=0;i<n;i++)
		{
			int temp;	cin>>temp;
			if(s.find(temp)!=s.end())
				s.erase(temp);
		}
		while(k--)
		{
			it=s.begin();
			s.erase(*it);
		}
		cout<<*(s.begin())<<endl;
	}
}

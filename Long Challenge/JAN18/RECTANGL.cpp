#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		set < int > s;
		set < int > :: iterator it;
		map < int,int > mp;
		for(int i=0;i<4;i++)
		{
			int t;	cin>>t;
			s.insert(t);
			mp[t]++;
		}
		string ans="NO";
		if(s.size()==2)	
		{
			ans="YES";
			for(it=s.begin();it!=s.end();it++)
				if(mp[*it]!=2)
					ans="NO";
		}
		if(s.size()==1)		ans="YES";
		cout<<ans<<endl;
	}
}

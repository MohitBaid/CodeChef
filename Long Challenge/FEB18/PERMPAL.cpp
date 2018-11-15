#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i,ans;	cin>>T;
	while(T--)
	{
		string a;	cin>>a;
		set < int > s[26];
		set < int > :: iterator it;
		for(i=0;i<a.size();i++)
		{
			s[a[i]-'a'].insert(i+1);
		}
		bool flag=true;
		if(a.size()%2==1)	flag=false;
		ans=0;
		for(i=0;i<26;i++)
		{
			if(s[i].size()%2==1)
			{
				if(!flag)
				{
					flag=true;
				}
				else
				{
					ans=-1;
					break;
				}
			}
		}
		if(ans==-1)	cout<<ans<<endl;
		else
		{
			int ans[a.size()];
			int m=0,p=-1;
			for(i=0;i<26;i++)
			{
				if(s[i].size()%2==0)
				{
					for(it=s[i].begin();it!=s[i].end();it++)
					{
						ans[m]=*it;
						m=a.size()-1-m;
						it++;
						ans[m]=*it;
						m=a.size()-m;
					}
					s[i].clear();
				}
				else
					p=i;
			}
			for(i=0;i<m;i++)
				cout<<ans[i]<<" ";
			if(p!=-1)
				for(it=s[p].begin();it!=s[p].end();it++)
					cout<<(*it)<<" ";
			m=a.size()-1-m;
			for(i=m+1;i<a.size();i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
}

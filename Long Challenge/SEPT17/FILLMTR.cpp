#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		cin>>T;
	while(T--)
	{
		int n,q;	cin>>n>>q;
		bool flag=true;
		set < pair < pair<int,int>,int > > s;
		set < pair < pair<int,int>,int > > :: iterator it,jt,kt;
		set < pair<int,int> > s0;
		set < pair<int,int> > :: iterator it0,it1;
		while(q--)
		{
			int i,j,val,temp;		
			cin>>i>>j>>val;
			if(i>j)
			{
				temp=i;
				i=j;
				j=temp;
			}
			it=s.find(make_pair(make_pair(i,j),val));
			jt=s.find(make_pair(make_pair(i,j),(val+1)%2));
			if(jt==s.end())
			{
				if(it==s.end())
					s.insert(make_pair(make_pair(i,j),val));
			}
			else					flag=false;
		}
		if(flag)
		{
			int c=1;
			for(it=s.begin();it!=s.end() && flag && c<=n;it++)
			{
				if(it->first.first==c)			s0.insert(make_pair(it->first.second,it->second));
				else
				{
					while(s0.size()>1 && flag)
					{
						it0=s0.begin();
						it1=it0;
						it1++;
						for(;it1!=s0.end() && flag ;it1++)
						{
							if(it0->second==it1->second)
							{
								kt=s.find(make_pair(make_pair((it0->first),(it1->first)),1));
								if(kt!=s.end())
								{
									flag= false;
									break;
								}
								else	s.insert(make_pair(make_pair((it0->first),(it1->first)),0));
							}
							else
							{
								kt=s.find(make_pair(make_pair((it0->first),(it1->first)),0));
								if(kt!=s.end())
								{
									flag= false;
									break;
								}
								else	s.insert(make_pair(make_pair((it0->first),(it1->first)),1));
							}
						}
						s0.erase(*it0);
					}
					s0.clear();
					c++;
					it--;
				}
			}
			while(s0.size()>1 && flag)
			{
				it0=s0.begin();
				it1=it0;
				it1++;
				for(;it1!=s0.end() && flag ;it1++)
				{
					if(it0->second==it1->second)
					{
						kt=s.find(make_pair(make_pair((it0->first),(it1->first)),1));
						if(kt!=s.end())
						{
							flag= false;
							break;
						}
						else	s.insert(make_pair(make_pair((it0->first),(it1->first)),0));
					}
					else
					{
						kt=s.find(make_pair(make_pair((it0->first),(it1->first)),0));
						if(kt!=s.end())
						{
							flag= false;
							break;
						}
						else	s.insert(make_pair(make_pair((it0->first),(it1->first)),1));
					}
				}
				s0.erase(*it0);
			}
		}
		if(flag)	cout<<"yes"<<endl;
		else		cout<<"no"<<endl;
	}
}

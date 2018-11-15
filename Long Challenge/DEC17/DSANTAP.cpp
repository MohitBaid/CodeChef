#include<bits/stdc++.h>
using namespace std;
set < pair < int , pair < int , pair < int,pair < int,int > > > > > p,r,l,t,f;
set < pair < int , pair < int , pair < int,pair < int,int > > > > > :: iterator it;
set < set < pair < int,int > > > bl;
set < set < pair < int,int > > > :: iterator blt;
int P[10000];
void collect(int i,int b)
{
	if(i==0)	t=l;
	else		t=r;
	multiset < int > te;
	multiset < int > ::iterator ite;
	while(t.size())
	{
		int g=0;
		for(it=t.begin();it!=t.end();it++)
		{
			if(g+P[it->second.second.second.first-1]<=b)
			{
				cout<<"1 "<<it->second.second.first<<endl;
				cout<<"2 "<<it->second.second.second.first<<endl;
				te.insert(it->second.second.second.first);
				f.insert(*it);
				g+=P[it->second.second.second.first-1];
			}
		}
		cout<<"1 0"<<endl;
		for(ite=te.begin();ite!=te.end();ite++)
		{
				cout<<"3 "<<*ite<<endl;
		}
		te.clear();
		for(it=f.begin();it!=f.end();it++)
		{
			t.erase(*it);
		}
		f.clear();
	}
}
void optimal(int i,int b)
{
	if(i==0)	t=l;
	else		t=r;
	set < pair < int,int > > te;
	set < pair < int,int > > :: iterator ite;
	while(t.size())
	{
		int g=0;
		for(it=t.begin();it!=t.end();it++)
		{
			if(g+P[it->second.second.second.second-1]<=b)
			{
				te.insert(make_pair(it->second.second.first,it->second.second.second.second));
				g+=P[it->second.second.second.second-1];	
				f.insert(*it);
			}
		}
		for(it=f.begin();it!=f.end();it++)
		{
			t.erase(*it);
		}
		bl.insert(te);
		te.clear();
		f.clear();
	}
}
void dispose()
{
	set < pair < int,int > > te;
	set < pair < int,int > > :: iterator ite;
	for(blt=bl.begin();blt!=bl.end();blt++)
	{
		te=*blt;
		set < int > s;
		for(ite=te.begin();ite!=te.end();ite++)
		{
			cout<<"2 "<<ite->second<<endl;
		}
		for(ite=te.begin();ite!=te.end();ite++)
		{
			cout<<"1 "<<ite->first<<endl;
			cout<<"3 "<<ite->second<<endl;
		}
		cout<<"1 0"<<endl;
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,g,b,x,y,i,j;	
		cin>>n>>g>>b>>x>>y;
		p.insert(make_pair(x,make_pair(y,make_pair(0,make_pair(-1,-1)))));
		for(i=0;i<g;i++)	cin>>P[i];
		for(i=1;i<=n;i++)	
		{
			int xi,yi,k,l;
			cin>>xi>>yi>>k>>l;
			p.insert(make_pair(xi,make_pair(yi,make_pair(i,make_pair(k,l)))));
		}
		bool flag=false;
		for(it=p.begin();it!=p.end();it++)
		{
			if(it->second.second.first!=0)
			{
				if(flag)
				{
					r.insert(*it);
				}
				else
				{
					l.insert(*it);
				}
			}
			else		flag=true;
		}
		collect(0,b);
		collect(1,b);
		optimal(0,b);
		optimal(1,b);
		dispose();
		p.clear();
		r.clear();
		l.clear();
		bl.clear();
		t.clear();
		f.clear();
		cout<<"0"<<endl;
	}
}

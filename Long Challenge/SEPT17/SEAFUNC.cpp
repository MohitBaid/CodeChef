#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,one=0,j;	cin>>n;
		char ch[n+2][n+2];
		for(i=0;i<n;i++)
		{
			cin>>ch[i];
			for(j=0;ch[i][j]!='\0';j++)
				if(ch[i][j]=='1')
					one++;	
		}
		set < pair <int,pair <int,int> > >s;
		for(i=0;i<n;i++)
		{
			int d=i,flag=0,c=0;
			for(j=0;j<n;j++)
			{
				if(ch[j][i]=='1')
				{
					if(!flag)	flag=1,c=1;
					else		c++;
				}
				else
				{
					if(c>0)	s.insert (make_pair (c*-1,make_pair(j-c,d)));
					flag=0;
					c=0;
				}
			}
			if(c>0)	s.insert (make_pair (c*-1,make_pair(j-c,d)));
		}
		set < pair <int,pair<int,int> > >:: iterator it;
		one-=100;
		if(one<=0)		cout<<"0\n";
		else
		{
			vector < vector < int > > v;
			vector < int > temp;
			vector < vector < int > > :: iterator jt;
			vector < int > :: iterator kt;
			for(it=s.begin();it!=s.end() && one>0;it++)
			{
				//cout<<"0 1 0 1 0 1 "<<it->second.second+1<<" "<<it->second.first+1<<" "<<it->second.first-it->first<<endl;
				temp.push_back(0);
				temp.push_back(1);
				temp.push_back(0);
				temp.push_back(1);
				temp.push_back(0);
				temp.push_back(1);
				temp.push_back(it->second.second+1);
				temp.push_back(it->second.first+1);
				temp.push_back(it->second.first-it->first);
				v.push_back(temp);
				temp.clear();
				one+=it->first;
			}
			cout<<v.size()<<endl;
			for(jt=v.begin();jt!=v.end();jt++)
			{
				temp=*jt;
				for(kt=temp.begin();kt!=temp.end();kt++)
				{
					cout<<*kt<<" ";
				}
				cout<<endl;
			}
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	set < vector < int > > s; 
	set < pair < vector < int > , vector < int > > > sv;
	set < vector < int > > :: iterator st;
	set < pair < vector < int > , vector < int > > > :: iterator sf; 
	map < vector < int > , int >  mp;
	map < vector < int > , int >  :: iterator mt;
	int i,j,k,l,m,m1,m2,n=7;
	int A[10]={1,2,3,4,5,6,7,8,9,10};
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				for(l=1;l<=n;l++)
				{
					for(m=1;m<=n;m++)
					{
						for(m1=1;m1<=n;m1++)
						{
							for(m2=1;m2<=n;m2++)
							{
								vector < int > b;
								b.push_back(i);
								b.push_back(j);
								b.push_back(k);
								b.push_back(l);
								b.push_back(m);
								b.push_back(m1);
								b.push_back(m2);
								s.insert(b);
								b.clear();
							}
						}
					}
				}
			}
		}
	}	
	for(st=s.begin();st!=s.end();st++)
	{
		for(i=0;i<n;i++)	A[i]=i+1;
		vector < int > b = *st;
		for(i=0;i<n;i++)
		{
			int k = b[i];
			swap(A[i],A[k-1]);
		}
		vector < int > bt;
		for(i=0;i<n;i++)
			bt.push_back(A[i]);
		mp[bt]++;
		sv.insert(make_pair(bt,b));
	}
	int min = 1000000,max=0;
	for(mt = mp.begin();mt!=mp.end();mt++)
	{
		if(mt->second<min)	min=mt->second;
		if(mt->second>max)	max=mt->second;
	}
	set < vector < int > > sr;
	for(mt = mp.begin();mt!=mp.end();mt++)
	{
		if(mt->second == min || mt->second == max)
		{
			vector < int > b = mt->first;
			for(i=0;i<n;i++)	cout<<b[i];		
			cout<<"     "<<mt->second<<endl;
			if(mt->second<min)	min=mt->second;
			sr.insert(b);
		}
	}
	/*for(mt = mp.begin();mt!=mp.end();mt++)
	{
		vector < int > b = mt->first;
		for(i=0;i<n;i++)	cout<<b[i];		
		cout<<"     "<<mt->second<<endl;
	}*/

	for(sf = sv.begin();sf!=sv.end();sf++)
	{
		vector < int > b = sf->first;
		if(sr.find(b)!=sr.end())
		{
			for(i=0;i<n;i++)	cout<<b[i];
					
			cout<<"     ";
			b.clear();
			b = sf->second;
			for(i=0;i<n;i++)	cout<<b[i];
			
			cout<<endl;
		}
	}
}
